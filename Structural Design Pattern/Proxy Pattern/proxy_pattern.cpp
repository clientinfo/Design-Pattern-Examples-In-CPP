#include "../../Includes.hpp"

namespace proxy_pattern_example
{
	real_image::real_image(std::string arg_file_name) : m_filename_(std::move(arg_file_name))
	{
		load_from_disk();
	}

	void real_image::display()
	{
		std::cout << "Displaying Real Image: " << m_filename_ << "\n";
	}

	void real_image::load_from_disk() const
	{
		std::cout << "Loading image from disk: " << m_filename_ << "\n";
	}

	image_proxy::image_proxy(std::string filename) : m_filename_(std::move(filename)), m_real_image_(nullptr)
	{
	}

	void image_proxy::display()
	{
		if (!m_real_image_)
		{
			m_real_image_ = std::make_unique<real_image>(m_filename_);
		}
		m_real_image_->display();
	}
}
