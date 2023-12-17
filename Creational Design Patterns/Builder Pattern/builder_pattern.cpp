#include "../../Includes.hpp"

namespace builder_pattern
{
	void computer::set_cpu(const std::string& arg_cpu)
	{
		m_cpu_ = arg_cpu;
	}

	void computer::set_ram(const std::string& arg_ram)
	{
		m_ram_ = arg_ram;
	}

	void computer::set_storage(const std::string& arg_storage)
	{
		m_storage_ = arg_storage;
	}

	void computer::show_info() const
	{
		std::cout << "Computer Configuration:\n";
		std::cout << "CPU: " << m_cpu_ << "\n";
		std::cout << "RAM: " << m_ram_ << "\n";
		std::cout << "Storage: " << m_storage_ << "\n";
	}

	void gaming_computer_builder::build_cpu()
	{
		m_computer_.set_cpu("High-Performance Gaming CPU");
	}

	void gaming_computer_builder::build_ram()
	{
		m_computer_.set_ram("16GB Gaming RAM");
	}

	void gaming_computer_builder::build_storage()
	{
		m_computer_.set_storage("1TB SSD");
	}

	void office_computer_builder::build_cpu()
	{
		m_computer_.set_cpu("Standard Office CPU");
	}

	void office_computer_builder::build_ram()
	{
		m_computer_.set_ram("8GB Office RAM");
	}

	void office_computer_builder::build_storage()
	{
		m_computer_.set_storage("500GB HDD");
	}

	computer office_computer_builder::get_result()
	{
		return m_computer_;
	}

	computer gaming_computer_builder::get_result()
	{
		return m_computer_;
	}

	computer computer_director::construct(computer_builder& arg_builder)
	{
		arg_builder.build_cpu();
		arg_builder.build_ram();
		arg_builder.build_storage();
		return arg_builder.get_result();
	}
}
