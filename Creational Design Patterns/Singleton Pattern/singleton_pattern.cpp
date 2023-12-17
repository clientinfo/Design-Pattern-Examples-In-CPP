#include "../../Includes.hpp"

namespace singleton_pattern_example
{
	std::shared_ptr<singleton_pattern> singleton_pattern::get_instance()
	{
		static auto r_instance = std::make_shared<singleton_pattern>();

		return r_instance;
	}

	void singleton_pattern::print_text_in_console(const std::string& arg_text)
	{
		std::cout << arg_text << '\n';
	}
}
