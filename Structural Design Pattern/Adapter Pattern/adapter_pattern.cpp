#include "../../Includes.hpp"

namespace adapter_pattern_example
{
	std::string legacy_database_impl::fetch_data() const
	{
		return "Data from Legacy Database";
	}

	std::wstring modern_database_impl::fetch_data() const
	{
		return L"Data from Modern Database";
	}

	database_adapter::database_adapter(legacy_database& arg_legacy_db) : m_legacy_database_(arg_legacy_db)
	{
	}

	std::wstring database_adapter::fetch_data() const
	{
		// Convert std::string to std::wstring
		std::string data_string = m_legacy_database_.fetch_data();
		std::wstring r_data(data_string.begin(), data_string.end());
		return r_data;
	}
}
