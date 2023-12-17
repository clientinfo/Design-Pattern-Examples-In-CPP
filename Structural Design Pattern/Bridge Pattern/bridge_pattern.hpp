#pragma once

namespace bridge_pattern_example
{
	/**
 * @brief The Color class is an implementor interface for colors.
 */
	class color
	{
	public:
		/**
		 * @brief Get the fill color.
		 * @return std::string The fill color.
		 */
		virtual std::string fill() const = 0;

		/**
		 * @brief Virtual destructor to ensure proper cleanup.
		 */
		virtual ~color() = default;
	};

	/**
	 * @brief The RedColor class is a concrete implementor class for the color red.
	 */
	class red_color final : public color
	{
	public:
		/**
		 * @brief Get the fill color.
		 * @return std::string The fill color.
		 */
		std::string fill() const override;
	};

	/**
	 * @brief The GreenColor class is a concrete implementor class for the color green.
	 */
	class green_color final : public color
	{
	public:
		/**
		 * @brief Get the fill color.
		 * @return std::string The fill color.
		 */
		std::string fill() const override;
	};

	/**
	 * @brief The Shape class is an abstraction interface for shapes.
	 */
	class shape
	{
	protected:
		std::shared_ptr<color> m_color_;

	public:
		/**
		 * @brief Construct a new Shape object with the given color.
		 * @param arg_color The color for the shape.
		 */
		explicit shape(const std::shared_ptr<color>& arg_color);

		/**
		 * @brief Draw the shape.
		 * @return std::string A string representing the drawn shape.
		 */
		virtual std::string draw() const = 0;

		/**
		 * @brief Virtual destructor to ensure proper cleanup.
		 */
		virtual ~shape() = default;
	};

	/**
	 * @brief The Circle class is a refined abstraction class representing a circle shape.
	 */
	class circle final : public shape
	{
	public:
		/**
		 * @brief Construct a new Circle object with the given color.
		 * @param arg_color The color for the circle.
		 */
		explicit circle(const std::shared_ptr<color>& arg_color);

		/**
		 * @brief Draw the circle.
		 * @return std::string A string representing the drawn circle.
		 */
		std::string draw() const override;
	};

	/**
	 * @brief The Square class is a refined abstraction class representing a square shape.
	 */
	class square final : public shape
	{
	public:
		/**
		 * @brief Construct a new Square object with the given color.
		 * @param arg_color The color for the square.
		 */
		explicit square(const std::shared_ptr<color>& arg_color);

		/**
		 * @brief Draw the square.
		 * @return std::string A string representing the drawn square.
		 */
		std::string draw() const override;
	};
}
