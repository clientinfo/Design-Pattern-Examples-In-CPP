#include "Includes.hpp"

/**
 * @brief Example function demonstrating the usage of the singleton pattern.
 *
 * This function showcases the creation of two instances of the singleton_pattern class
 * using smart pointers. It then checks if both instances are identical, illustrating
 * the effectiveness of the singleton design pattern. Finally, it calls a function from the
 * singleton instance to print a message to the console.
 */
void singleton_example()
{
	// Access to the singleton_pattern class via a smart pointer
	const std::shared_ptr<singleton_pattern_example::singleton_pattern> singleton_instance1 =
		singleton_pattern_example::singleton_pattern::get_instance();

	const std::shared_ptr<singleton_pattern_example::singleton_pattern> singleton_instance2 =
		singleton_pattern_example::singleton_pattern::get_instance();

	std::cout << "------------------------Singleton Pattern Example------------------------" << '\n';

	// Both instances are identical because of the singleton design pattern
	if (singleton_instance1 == singleton_instance2)
	{
		std::cout << "Both instances are identical. The singleton design pattern works!" << '\n';
	}

	std::cout << "Calling Function From Object" << '\n';

	// Example of function call
	singleton_instance1->print_text_in_console("Hello World!");
}

/**
 * @brief Demonstrates the usage of the Factory Pattern with CheeseBurger and VeggieBurger factories.
 *
 * This function creates instances of burgers using concrete factories, such as CheeseBurger Factory and VeggieBurger Factory.
 * It displays the preparation, cooking, and serving steps for both Cheeseburger and Veggieburger.
 */
void factory_example()
{
	std::cout << "------------------------Factory Pattern Example------------------------" << '\n';

	// Using the CheeseBurger Factory
	const auto cheese_burger_factory = std::make_unique<factory_pattern_example::cheese_burger_factory>();
	const std::shared_ptr<factory_pattern_example::burger> cheese_burger = cheese_burger_factory->create_burger();

	// Display the preparation, cooking, and serving of the Cheeseburger
	cheese_burger->prepare();
	cheese_burger->cook();
	cheese_burger->serve();

	// Using the VeggieBurger Factory
	const auto veggie_burger_factory = std::make_unique<factory_pattern_example::veggie_burger_factory>();
	const std::shared_ptr<factory_pattern_example::burger> veggie_burger = veggie_burger_factory->create_burger();

	// Display the preparation, cooking, and serving of the Veggieburger
	veggie_burger->prepare();
	veggie_burger->cook();
	veggie_burger->serve();
}

/**
 * @brief Function to demonstrate the Builder Pattern with gaming and office computers.
 *
 * The function creates instances of gaming and office computer builders, directs the construction
 * of computers using directors, and displays their configurations.
 */
void builder_example()
{
	std::cout << "------------------------Builder Pattern Example------------------------" << '\n';

	// Gaming Computer
	builder_pattern::gaming_computer_builder gaming_builder;
	const builder_pattern::computer gaming_computer = builder_pattern::computer_director::construct(gaming_builder);

	std::cout << "Gaming Computer Configuration:\n";
	gaming_computer.show_info();
	std::cout << "\n";

	std::cout << "------------------------------------------------------------------------" << '\n';
	// Office Computer
	builder_pattern::office_computer_builder office_builder;
	builder_pattern::computer office_computer = builder_pattern::computer_director::construct(office_builder);

	std::cout << "Office Computer Configuration:\n";
	office_computer.show_info();
}

/**
 * @brief Example function demonstrating the Prototype pattern.
 *
 * This function showcases the use of the Prototype pattern by creating prototype instances
 * of circle and square shapes. It then creates copies of these shapes using the prototype's
 * `clone_shape` method and draws the copied shapes.
 */
void prototype_example()
{
	std::cout << "------------------------Prototype Pattern Example------------------------" << '\n';

	// Creating prototypes
	const auto circle_prototype = std::make_unique<prototype_pattern_example::circle>();
	const auto square_prototype = std::make_unique<prototype_pattern_example::square>();

	// Creating copies using the prototypes
	const auto copy_of_circle_instance = circle_prototype->clone_shape();
	const auto copy_of_square_instance = square_prototype->clone_shape();

	// Drawing the shapes
	copy_of_circle_instance->draw();
	copy_of_square_instance->draw();
}

/**
 * @brief Example function demonstrating the Facade pattern.
 *
 * This function showcases the use of the Facade pattern by using the Car Facade to start and stop the car.
 */
void facade_example()
{
	std::cout << "------------------------Facade Pattern Example------------------------\n";

	// Using the Car Facade to start and stop the car
	facade_pattern_example::car_facade::start_car();
	facade_pattern_example::car_facade::stop_car();

	std::cout << "------------------------------------------------------------------------\n";
}

/**
 * @brief Example function demonstrating the Proxy pattern.
 *
 * This function showcases the use of the Proxy pattern by creating a Real Image and using it directly.
 * It also creates an ImageProxy, which will create a Real Image only when necessary, and displays it.
 */
void proxy_example()
{
	std::cout << "------------------------Proxy Pattern Example------------------------\n";
	// Creating a Real Image
	proxy_pattern_example::real_image real_image("test.jpg");

	// Using the RealImage directly
	std::cout << "Displaying RealImage directly:\n";
	real_image.display();
	std::cout << '\n';

	// Creating an ImageProxy
	proxy_pattern_example::image_proxy proxy_image("example.jpg");

	// Using the ImageProxy, which will create a RealImage only when necessary
	std::cout << "Displaying ImageProxy:\n";
	proxy_image.display();
}

/**
 * @brief Example function demonstrating the Decorator Pattern.
 *
 * This function creates a simple coffee and decorates it with milk and sugar,
 * displaying the cost and ingredients after each decoration.
 */
void decorator_example()
{
	std::cout << "------------------------Decorator Pattern Example------------------------\n";

	// Creating a simple coffee
	std::shared_ptr<decorator_pattern_example::coffee> my_coffee = std::make_shared<
		decorator_pattern_example::simple_coffee>();
	std::cout << "Cost: " << my_coffee->get_cost() << ", Ingredients: " << my_coffee->get_description() << '\n';

	// Decorating with Milk
	my_coffee = std::make_shared<decorator_pattern_example::milk_decorator>(my_coffee);
	std::cout << "Cost: " << my_coffee->get_cost() << ", Ingredients: " << my_coffee->get_description() << '\n';

	// Decorating with Sugar
	my_coffee = std::make_shared<decorator_pattern_example::sugar_decorator>(my_coffee);
	std::cout << "Cost: " << my_coffee->get_cost() << ", Ingredients: " << my_coffee->get_description() << '\n';
}


/**
 * @brief The flyweight_example function demonstrates the usage of the Flyweight
 * Pattern by creating a coffee flavor factory and serving different coffee flavors.
 */
void flyweight_example()
{
	std::cout << "------------------------Flyweight Pattern Example------------------------\n";

	// Create a coffee flavor factory
	flyweight_pattern_example::coffee_flavor_factory flavor_factory;

	// Get or create coffee flavors using the factory
	const flyweight_pattern_example::coffee_flavor* cappuccino = flavor_factory.get_coffee_flavor("Cappuccino");
	const flyweight_pattern_example::coffee_flavor* espresso = flavor_factory.get_coffee_flavor("Espresso");
	const flyweight_pattern_example::coffee_flavor* americano = flavor_factory.get_coffee_flavor("Americano");

	// Serve coffee flavors
	cappuccino->serve_coffee();
	espresso->serve_coffee();
	americano->serve_coffee();
}

void adapter_example()
{
	std::cout << "------------------------Adapter Pattern Example------------------------\n";

	// Create instances of the legacy and modern databases
	adapter_pattern_example::legacy_database_impl legacy_db;
	const adapter_pattern_example::modern_database_impl modern_db;

	// Use the legacy database directly
	std::cout << "Legacy Database Output: " << legacy_db.fetch_data() << '\n';

	// Use the modern database directly
	std::wcout << L"Modern Database Output: " << modern_db.fetch_data() << '\n';

	// Create an adapter to make the legacy database compatible with the modern database interface
	const adapter_pattern_example::database_adapter adapter(legacy_db);

	// Use the adapter to fetch data, treating the legacy database as if it were a modern database
	std::wcout << L"Adapter Output: " << adapter.fetch_data() << '\n';
}

/**
 * @brief Demonstrates the Bridge Pattern with shapes and colors.
 *
 * This example creates instances of shapes (circle and square) with different colors (red and green).
 * The Bridge Pattern allows varying shapes and colors independently, promoting flexibility and extensibility.
 */
void bridge_example()
{
	std::cout << "------------------------Bridge Pattern Example------------------------\n";
	// Create instances of colors
	auto red_color = std::make_shared<bridge_pattern_example::red_color>();
	auto green_color = std::make_shared<bridge_pattern_example::green_color>();

	// Create instances of shapes with different colors
	const auto red_circle = std::make_unique<bridge_pattern_example::circle>(red_color);
	const auto green_circle = std::make_unique<bridge_pattern_example::circle>(green_color);
	const auto green_square = std::make_unique<bridge_pattern_example::square>(green_color);
	const auto red_square = std::make_unique<bridge_pattern_example::square>(red_color);

	// Draw shapes with their respective colors
	std::cout << red_circle->draw() << '\n';
	std::cout << green_circle->draw() << '\n';
	std::cout << green_square->draw() << '\n';
	std::cout << red_square->draw() << '\n';
}

int main()
{
	///Uncomment the example which you wanna see in action

	//Creational Design Pattern
	//singleton_example();
	//factory_example();
	//builder_example();
	//prototype_example();

	//Structural Design Pattern
	//facade_example();
	//proxy_example();
	//decorator_example();
	//flyweight_example();
	//adapter_example();
	//bridge_example();
}
