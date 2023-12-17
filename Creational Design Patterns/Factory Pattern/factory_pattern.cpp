#include "../../Includes.hpp"

namespace factory_pattern_example
{
	void cheese_burger::prepare() const
	{
		std::cout << "Preparing Cheeseburger..." << '\n';
	}

	void cheese_burger::cook() const
	{
		std::cout << "Cooking Cheeseburger..." << '\n';
	}

	void cheese_burger::serve() const
	{
		std::cout << "Serving Cheeseburger." << '\n';
	}

	void veggie_burger::prepare() const
	{
		std::cout << "Preparing Veggieburger..." << '\n';
	}

	void veggie_burger::cook() const
	{
		std::cout << "Cooking Veggieburger..." << '\n';
	}

	void veggie_burger::serve() const
	{
		std::cout << "Serving Veggieburgers" << '\n';
	}

	std::shared_ptr<burger> cheese_burger_factory::create_burger()
	{
		return std::make_shared<cheese_burger>();
	}

	std::shared_ptr<burger> veggie_burger_factory::create_burger()
	{
		return std::make_shared<veggie_burger>();
	}
}
