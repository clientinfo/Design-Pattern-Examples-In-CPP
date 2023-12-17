#include "../../Includes.hpp"

namespace decorator_pattern_example
{
	std::string simple_coffee::get_description() const
	{
		return "Simple Coffee";
	}

	double simple_coffee::get_cost() const
	{
		return 1.0;
	}

	coffee_decorator::coffee_decorator(std::shared_ptr<coffee> arg_coffee) : m_coffee_(arg_coffee)
	{
	}

	std::string coffee_decorator::get_description() const
	{
		return m_coffee_->get_description();
	}

	double coffee_decorator::get_cost() const
	{
		return m_coffee_->get_cost();
	}

	milk_decorator::milk_decorator(std::shared_ptr<coffee> arg_coffee) : coffee_decorator(arg_coffee)
	{
	}

	std::string milk_decorator::get_description() const
	{
		return coffee_decorator::get_description() + ", Milk";
	}

	double milk_decorator::get_cost() const
	{
		return coffee_decorator::get_cost() + 0.5;
	}

	sugar_decorator::sugar_decorator(std::shared_ptr<coffee> arg_coffee) : coffee_decorator(arg_coffee)
	{
	}

	std::string sugar_decorator::get_description() const
	{
		return coffee_decorator::get_description() + ", Sugar";
	}

	double sugar_decorator::get_cost() const
	{
		return coffee_decorator::get_cost() + 0.2;
	}
}
