#include "../../Includes.hpp"

namespace flyweight_pattern_example
{
	coffee_flavor_impl::coffee_flavor_impl(std::string arg_flavor) : m_flavor_(std::move(arg_flavor))
	{
	}

	void coffee_flavor_impl::serve_coffee() const
	{
		std::cout << "Serving coffee flavor: " << m_flavor_ << '\n';
	}

	coffee_flavor_impl* coffee_flavor_factory::get_coffee_flavor(const std::string& arg_flavor)
	{
		// Check if the flavor exists in the factory
		const auto it = m_flavors_.find(arg_flavor);

		// If the flavor doesn't exist, create a new one and add it to the factory
		if (it == m_flavors_.end())
		{
			const auto r_new_flavor = new coffee_flavor_impl(arg_flavor);
			m_flavors_[arg_flavor] = r_new_flavor;
			return r_new_flavor;
		}
		// If the flavor already exists, return the existing one
		return it->second;
	}

	coffee_flavor_factory::~coffee_flavor_factory()
	{
		// Clean up: delete all created flavors
		for (const auto& entry : m_flavors_)
		{
			delete entry.second;
		}
	}
}
