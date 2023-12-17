#pragma once

namespace singleton_pattern_example
{
	/**
	* @brief Singleton pattern implementation class.
	*
	* This class provides a simple example of the singleton pattern, it makes sure that
	* only one instance of the class can exist. It includes static methods to access
	* the singleton instance and perform actions.
	*/
	class singleton_pattern
	{
	public:
		/**
		 * @brief Static function to get the singleton instance.
		 *
		 * This function returns a shared pointer to the singleton instance. The first
		 * call creates a new instance, and subsequent calls return the existing instance.
		 *
		 * @return std::shared_ptr<singleton_pattern> The singleton instance.
		 */
		static std::shared_ptr<singleton_pattern> get_instance();

		/**
		 * @brief Static function to print text to the console.
		 *
		 * This function takes a string as an argument and prints it to the console.
		 *
		 * @param arg_text The text to be printed.
		 */
		static void print_text_in_console(const std::string& arg_text);
	};
}
