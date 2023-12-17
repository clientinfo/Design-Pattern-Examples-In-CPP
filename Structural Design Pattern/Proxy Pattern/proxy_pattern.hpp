#pragma once

namespace proxy_pattern_example
{
	/**
	 * @brief The Subject interface declares common operations for both RealSubject
	 *        and Proxy.
	 */
	class image
	{
	public:
		/**
		 * @brief Displays the image.
		 */
		virtual void display() = 0;

		/**
		 * @brief Virtual destructor to ensure proper cleanup.
		 */
		virtual ~image() = default;
	};

	/**
	 * @brief The RealSubject class provides the actual implementation of the Image
	 *        interface.
	 */
	class real_image final : public image
	{
		std::string m_filename_;

	public:
		/**
		 * @brief Constructs a RealImage with a given filename.
		 * @param arg_file_name The filename of the image.
		 */
		explicit real_image(std::string arg_file_name = "");

		/**
		 * @brief Displays the image.
		 */
		void display() override;

	private:
		/**
		 * @brief Loads the image from disk.
		 */
		void load_from_disk() const;
	};

	/**
	 * @brief The Proxy class provides a surrogate or placeholder for another
	 *        object to control access to it.
	 */
	class image_proxy final : public image
	{
		std::string m_filename_;
		std::unique_ptr<real_image> m_real_image_;

	public:
		/**
		 * @brief Constructs an ImageProxy with a given filename.
		 * @param filename The filename of the image.
		 */
		explicit image_proxy(std::string filename = "");

		/**
		 * @brief Displays the image. If the RealImage instance is not created,
		 *        it creates one before displaying.
		 */
		void display() override;
	};
}
