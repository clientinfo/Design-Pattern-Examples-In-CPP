#pragma once
namespace factory_pattern_example
{
	/**
	* @brief Abstract base class for burgers.
	*/
	class burger
	{
	public:
		virtual void prepare() const = 0;
		virtual void cook() const = 0;
		virtual void serve() const = 0;
		virtual ~burger() = default;
	};

	/**
	* @brief Concrete implementation of a cheeseburger.
	*/
	class cheese_burger final : public burger
	{
	public:
		void prepare() const override;
		void cook() const override;
		void serve() const override;
	};

	/**
	 * @brief Concrete implementation of a veggie burger.
	 */
	class veggie_burger final : public burger
	{
	public:
		void prepare() const override;
		void cook() const override;
		void serve() const override;
	};

	/**
	 * @brief Abstract factory class for creating burgers.
	 */
	class burger_factory
	{
	public:
		virtual std::shared_ptr<burger> create_burger() = 0;
		virtual ~burger_factory() = default;
	};

	/**
	 * @brief Concrete factory for creating cheeseburgers.
	 */
	class cheese_burger_factory final : public burger_factory
	{
	public:
		/**
		 * @brief Creates a new instance of a cheeseburger.
		 * @return A shared pointer to the created cheeseburger.
		 */
		std::shared_ptr<burger> create_burger() override;
	};

	/**
	 * @brief Concrete factory for creating veggie burgers.
	 */
	class veggie_burger_factory final : public burger_factory
	{
	public:
		/**
		 * @brief Creates a new instance of a veggie burger.
		 * @return A shared pointer to the created veggie burger.
		 */
		std::shared_ptr<burger> create_burger() override;
	};
}
