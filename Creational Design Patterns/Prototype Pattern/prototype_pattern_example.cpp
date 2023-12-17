#include "../../Includes.hpp"

namespace prototype_pattern_example
{
	std::unique_ptr<shape> circle::clone_shape() const
	{
		return std::make_unique<circle>(*this);
	}

	void circle::draw() const
	{
		std::cout << "Drawing Circle\n";
	}

	std::unique_ptr<shape> square::clone_shape() const
	{
		return std::make_unique<square>(*this);
	}

	void square::draw() const
	{
		std::cout << "Drawing Square\n";
	}
}
