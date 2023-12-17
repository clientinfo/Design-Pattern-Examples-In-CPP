#pragma once

namespace decorator_pattern_example
{
	/**
	 * @brief The Coffee class represents the Component interface.
	 */
	class coffee
	{
	public:
		/**
		 * @brief Virtual destructor to ensure proper cleanup.
		 */
		virtual ~coffee() = default;

		/**
		 * @brief Get the description of the coffee.
		 * @return std::string The description of the coffee.
		 */
		virtual std::string get_description() const = 0;

		/**
		 * @brief Get the cost of the coffee.
		 * @return double The cost of the coffee.
		 */
		virtual double get_cost() const = 0;
	};

	/**
	 * @brief The SimpleCoffee class is a Concrete Component.
	 */
	class simple_coffee final : public coffee
	{
	public:
		/**
		 * @brief Get the description of the simple coffee.
		 * @return std::string The description of the simple coffee.
		 */
		std::string get_description() const override;

		/**
		 * @brief Get the cost of the simple coffee.
		 * @return double The cost of the simple coffee.
		 */
		double get_cost() const override;
	};

	/**
	 * @brief The CoffeeDecorator class is the Decorator.
	 */
	class coffee_decorator : public coffee
	{
	protected:
		/**
		 * @brief Constructs a CoffeeDecorator with a given coffee.
		 * @param arg_coffee The coffee to decorate.
		 */
		coffee_decorator(std::shared_ptr<coffee> arg_coffee);

	public:
		/**
		 * @brief Get the description of the decorated coffee.
		 * @return std::string The description of the decorated coffee.
		 */
		std::string get_description() const override;

		/**
		 * @brief Get the cost of the decorated coffee.
		 * @return double The cost of the decorated coffee.
		 */
		double get_cost() const override;

	private:
		std::shared_ptr<coffee> m_coffee_;
	};

	/**
	 * @brief The MilkDecorator class is a Concrete Decorator.
	 */
	class milk_decorator final : public coffee_decorator
	{
	public:
		/**
		 * @brief Constructs a MilkDecorator with a given coffee.
		 * @param arg_coffee The coffee to decorate with milk.
		 */
		explicit milk_decorator(std::shared_ptr<coffee> arg_coffee);

		/**
		 * @brief Get the description of the coffee with milk.
		 * @return std::string The description of the coffee with milk.
		 */
		std::string get_description() const override;

		/**
		 * @brief Get the cost of the coffee with milk.
		 * @return double The cost of the coffee with milk.
		 */
		double get_cost() const override;
	};

	/**
	 * @brief The SugarDecorator class is a Concrete Decorator.
	 */
	class sugar_decorator final : public coffee_decorator
	{
	public:
		/**
		 * @brief Constructs a SugarDecorator with a given coffee.
		 * @param arg_coffee The coffee to decorate with sugar.
		 */
		explicit sugar_decorator(std::shared_ptr<coffee> arg_coffee);

		/**
		 * @brief Get the description of the coffee with sugar.
		 * @return std::string The description of the coffee with sugar.
		 */
		std::string get_description() const override;

		/**
		 * @brief Get the cost of the coffee with sugar.
		 * @return double The cost of the coffee with sugar.
		 */
		double get_cost() const override;
	};
}
