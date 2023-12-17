#include "../../Includes.hpp"

namespace bridge_pattern_example
{
	std::string red_color::fill() const
	{
		return "Red";
	}

	std::string green_color::fill() const
	{
		return "Green";
	}

	shape::shape(const std::shared_ptr<color>& arg_color) : m_color_(arg_color)
	{
	}

	circle::circle(const std::shared_ptr<color>& arg_color) : shape(arg_color)
	{
	}

	std::string circle::draw() const
	{
		return "Drawing Circle with color: " + m_color_->fill();
	}

	square::square(const std::shared_ptr<color>& arg_color) : shape(arg_color)
	{
	}

	std::string square::draw() const
	{
		return "Drawing Square with color: " + m_color_->fill();
	}
}
