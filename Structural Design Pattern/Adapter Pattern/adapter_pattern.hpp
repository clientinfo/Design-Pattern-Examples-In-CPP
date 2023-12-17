#pragma once

namespace adapter_pattern_example
{
	/**
	 * @brief The legacy_database class is the System 1 interface representing a legacy database.
	 */
	class legacy_database
	{
	public:
		/**
		 * @brief Fetches data from the legacy database.
		 * @return std::string The fetched data.
		 */
		virtual std::string fetch_data() const = 0;

		/**
		 * @brief Virtual destructor to ensure proper cleanup.
		 */
		virtual ~legacy_database() = default;
	};

	/**
	 * @brief The legacy_database_impl class is the implementation of the legacy_database interface.
	 */
	class legacy_database_impl final : public legacy_database
	{
	public:
		/**
		 * @brief Fetches data from the legacy database.
		 * @return std::string The fetched data.
		 */
		std::string fetch_data() const override;
	};

	/**
	 * @brief The modern_database class is the System 2 interface representing a modern database.
	 */
	class modern_database
	{
	public:
		/**
		 * @brief Fetches data from the modern database.
		 * @return std::wstring The fetched data.
		 */
		virtual std::wstring fetch_data() const = 0;

		/**
		 * @brief Virtual destructor to ensure proper cleanup.
		 */
		virtual ~modern_database() = default;
	};

	/**
	 * @brief The modern_database_impl class is the implementation of the modern_database interface.
	 */
	class modern_database_impl final : public modern_database
	{
	public:
		/**
		 * @brief Fetches data from the modern database.
		 * @return std::wstring The fetched data.
		 */
		std::wstring fetch_data() const override;
	};

	/**
	 * @brief The database_adapter class is the Adapter to make legacy_database compatible with modern_database.
	 */
	class database_adapter final : public modern_database
	{
	public:
		/**
		 * @brief Constructs a database_adapter with a reference to a legacy_database.
		 * @param arg_legacy_db The legacy_database to adapt.
		 */
		explicit database_adapter(legacy_database& arg_legacy_db);

		/**
		 * @brief Fetches data using the adapted legacy_database.
		 * @return std::wstring The fetched data.
		 */
		std::wstring fetch_data() const override;

	private:
		legacy_database& m_legacy_database_;
	};
}
