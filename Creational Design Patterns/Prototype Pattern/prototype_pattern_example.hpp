#pragma once

namespace prototype_pattern_example
{
	// Prototype (Shape)
	class shape
	{
	public:
		virtual ~shape() = default;

		/**
		 * @brief Clone the current shape.
		 * @return A unique pointer to a new instance of the cloned shape.
		 */
		virtual std::unique_ptr<shape> clone_shape() const = 0;

		/**
		 * @brief "Draw" the shape.
		 */
		virtual void draw() const = 0;
	};

	// Concrete Prototypes (Circle and Square)
	class circle final : public shape
	{
	public:
		/**
		 * @brief Clone the current circle.
		 * @return A unique pointer to a new instance of the cloned circle.
		 */
		std::unique_ptr<shape> clone_shape() const override;

		/**
		 * @brief "Draw" the circle.
		 */
		void draw() const override;
	};

	class square final : public shape
	{
	public:
		/**
		 * @brief Clone the current square.
		 * @return A unique pointer to a new instance of the cloned square.
		 */
		std::unique_ptr<shape> clone_shape() const override;

		/**
		 * @brief "Draw" the square.
		 */
		void draw() const override;
	};
}
