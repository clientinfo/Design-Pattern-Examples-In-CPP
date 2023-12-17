#pragma once

namespace builder_pattern
{
	// Product
	class computer
	{
	public:
		/**
		 * @brief Set the CPU of the computer.
		 *
		 * @param arg_cpu The CPU information.
		 */
		void set_cpu(const std::string& arg_cpu);

		/**
		 * @brief Set the RAM of the computer.
		 *
		 * @param arg_ram The RAM information.
		 */
		void set_ram(const std::string& arg_ram);

		/**
		 * @brief Set the storage of the computer.
		 *
		 * @param arg_storage The storage information.
		 */
		void set_storage(const std::string& arg_storage);

		/**
		 * @brief Display the information about the computer.
		 */
		void show_info() const;

	private:
		std::string m_cpu_; ///< CPU information.
		std::string m_ram_; ///< RAM information.
		std::string m_storage_; ///< Storage information.
	};

	// Builder Interface
	class computer_builder
	{
	public:
		virtual ~computer_builder() = default;

		/**
		 * @brief Build the CPU for the computer.
		 */
		virtual void build_cpu() = 0;

		/**
		 * @brief Build the RAM for the computer.
		 */
		virtual void build_ram() = 0;

		/**
		 * @brief Build the storage for the computer.
		 */
		virtual void build_storage() = 0;

		/**
		 * @brief Get the result of the constructed computer.
		 *
		 * @return The constructed computer.
		 */
		virtual computer get_result() = 0;
	};

	// Concrete Builder
	class gaming_computer_builder final : public computer_builder
	{
	public:
		void build_cpu() override;
		void build_ram() override;
		void build_storage() override;

		/**
		 * @brief Get the result of the constructed gaming computer.
		 *
		 * @return The constructed gaming computer.
		 */
		computer get_result() override;

	private:
		computer m_computer_; ///< The gaming computer being constructed.
	};

	// Concrete Builder
	class office_computer_builder final : public computer_builder
	{
	public:
		void build_cpu() override;
		void build_ram() override;
		void build_storage() override;

		/**
		 * @brief Get the result of the constructed office computer.
		 *
		 * @return The constructed office computer.
		 */
		computer get_result() override;

	private:
		computer m_computer_; ///< The office computer being constructed.
	};

	// Director
	class computer_director
	{
	public:
		/**
		 * @brief Construct a computer using the provided builder.
		 *
		 * @param arg_builder The builder for constructing the computer.
		 * @return The constructed computer.
		 */
		static computer construct(computer_builder& arg_builder);
	};
}
