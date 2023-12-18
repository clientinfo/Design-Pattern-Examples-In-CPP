# C++ Design Patterns Examples

This repository contains examples of various design patterns implemented in C++. 

Each design pattern is demonstrated with a simple and clear example.

If you take a look into the ```main.cpp``` you will find functions with each PoC (They are commented).

If you want to see one in action, you will need to uncomment the desired one to see it in action.

The folder structure should be clear enough, where you can find the code of each example.

# Singleton Pattern Example

## Overview

This example demonstrates the implementation of the Singleton pattern, which ensures that only one instance of a class can exist.

In this case, we have a `singleton_pattern` class that provides a simple illustration of the Singleton pattern.

## Singleton Pattern Class

### Class Definition

The `singleton_pattern` class is designed to have only one instance throughout the program's execution.

It includes the following methods:

#### `get_instance()`

Static method that returns a shared pointer to the singleton instance.

If the instance doesn't exist, it is created. Otherwise, the existing instance is returned.

#### `print_text_in_console(const std::string& arg_text)`

Static method that takes a string argument and prints it to the console.

## Example Usage

```cpp
    // Get the singleton instance
    auto singleton_instance = singleton_pattern_example::singleton_pattern::get_instance();

    // Print text using the singleton instance
    singleton_instance->print_text_in_console("Hello, Singleton!");
```

# Factory Pattern Example

## Overview

This example demonstrates the Factory pattern, a creational pattern that provides an interface for creating objects in a super class, but allows subclasses to alter the type of objects that will be created.

In this example, we have a `burger` interface with concrete implementations `cheese_burger` and `veggie_burger`. Additionally, there are factory classes `cheese_burger_factory` and `veggie_burger_factory` responsible for creating instances of the corresponding burgers.

## Factory Pattern Classes

### Product Interface: `burger`

The `burger` interface declares methods that concrete products must implement.

#### Methods:
- `prepare()`: Prepare the burger.
- `cook()`: Cook the burger.
- `serve()`: Serve the burger.

### Concrete Products: `cheese_burger` and `veggie_burger`

These classes implement the `burger` interface to represent specific types of burgers.

### Factory Interface: `burger_factory`

The `burger_factory` interface declares a method to create a `burger`.

#### Method:
- `create_burger()`: Create an instance of `burger`.

### Concrete Factories: `cheese_burger_factory` and `veggie_burger_factory`

These classes implement the `burger_factory` interface to create specific types of burgers.

## Example Usage

```cpp
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
```
# Builder Pattern Example

## Overview

This example demonstrates the Builder pattern, a creational pattern that separates the construction of a complex object from its representation. It allows the same construction process to create different representations.

In this example, we have a `computer` class representing a computer configuration, a `computer_builder` interface with concrete implementations `gaming_computer_builder` and `office_computer_builder`, and a `computer_director` class that constructs a computer using a specified builder.

## Builder Pattern Classes

### Product: `computer`

The `computer` class represents the complex object to be constructed.

#### Methods:
- `set_cpu(const std::string& arg_cpu)`: Set the CPU of the computer.
- `set_ram(const std::string& arg_ram)`: Set the RAM of the computer.
- `set_storage(const std::string& arg_storage)`: Set the storage of the computer.
- `show_info() const`: Display information about the computer.

### Builder Interface: `computer_builder`

The `computer_builder` interface declares methods to build different parts of the `computer`.

#### Methods:
- `build_cpu()`: Build the CPU for the computer.
- `build_ram()`: Build the RAM for the computer.
- `build_storage()`: Build the storage for the computer.
- `get_result()`: Get the result of the constructed computer.

### Concrete Builders: `gaming_computer_builder` and `office_computer_builder`

These classes implement the `computer_builder` interface to construct specific types of computers.

### Director: `computer_director`

The `computer_director` class constructs a computer using a specified builder.

#### Methods:
- `construct(computer_builder& arg_builder)`: Construct a computer using the provided builder.

## Example Usage

```cpp
// Create a gaming computer using the gaming computer builder
auto gaming_builder = builder_pattern::gaming_computer_builder();
auto gaming_computer = builder_pattern::computer_director::construct(gaming_builder);

// Display information about the gaming computer
gaming_computer.show_info();
// Create an office computer using the office computer builder
auto office_builder = builder_pattern::office_computer_builder();
auto office_computer = builder_pattern::computer_director::construct(office_builder);

// Display information about the office computer
office_computer.show_info();
```

# Prototype Pattern Example

## Overview

This example demonstrates the Prototype pattern, a creational pattern that creates new objects by copying an existing object, known as the prototype. It allows the creation of new objects with the same properties as an existing object, avoiding the need to create a new instance from scratch.

In this example, we have a `shape` interface representing a geometric shape and concrete implementations `circle` and `square`. The concrete shapes provide a method to clone themselves.

## Prototype Pattern Classes

### Prototype: `shape`

The `shape` interface declares methods for cloning the shape and drawing it.

#### Methods:
- `clone_shape() const`: Clone the current shape.
- `draw() const`: "Draw" the shape.

### Concrete Prototypes: `circle` and `square`

These classes implement the `shape` interface and provide methods to clone themselves and draw.

#### Methods:
- `clone_shape() const`: Clone the current shape.
- `draw() const`: "Draw" the shape.

## Example Usage

```cpp
// Creating prototypes
const auto circle_prototype = std::make_unique<prototype_pattern_example::circle>();
const auto square_prototype = std::make_unique<prototype_pattern_example::square>();

// Creating copies using the prototypes
const auto copy_of_circle_instance = circle_prototype->clone_shape();
const auto copy_of_square_instance = square_prototype->clone_shape();

// Drawing the shapes
copy_of_circle_instance->draw();
copy_of_square_instance->draw();
```
