#pragma once

namespace flyweight_pattern_example
{
	/**
	 * @brief The coffee_flavor class is the Flyweight interface.
	 */
	class coffee_flavor
	{
	public:
		virtual void serve_coffee() const = 0;
	};

	/**
	 * @brief The coffee_flavor_impl class is a Concrete Flyweight that implements the coffee_flavor interface.
	 */
	class coffee_flavor_impl : public coffee_flavor
	{
	public:
		/**
		 * @brief Constructs a coffee_flavor_impl with a given flavor.
		 * @param arg_flavor The flavor of the coffee.
		 */
		explicit coffee_flavor_impl(std::string arg_flavor);

		/**
		 * @brief Serves the coffee flavor.
		 */
		void serve_coffee() const override;

	private:
		std::string m_flavor_;
	};

	/**
	 * @brief The coffee_flavor_factory class is the Flyweight Factory.
	 */
	class coffee_flavor_factory
	{
	public:
		/**
		 * @brief Gets a coffee flavor from the factory.
		 * @param arg_flavor The flavor of the coffee.
		 * @return A pointer to the coffee_flavor_impl instance.
		 */
		coffee_flavor_impl* get_coffee_flavor(const std::string& arg_flavor);

		/**
		 * @brief Destructor to clean up created flavors.
		 */
		~coffee_flavor_factory();

	private:
		std::unordered_map<std::string, coffee_flavor_impl*> m_flavors_;
	};
}
