# C++ Design Patterns Examples

This repository contains examples of various design patterns implemented in C++. 

Each design pattern is demonstrated with a simple and clear example.

If you take a look into the ```main.cpp``` you will find functions with each POC (They are commented).

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

Factory Pattern makes it easy to create multiple diffrent objects by providing an interface for creating objects without specifying their concrete classes.

It encapsulates object creation in factories, allowing clients to create objects without knowing their specific types. 

This pattern allows easy extension by adding new classes or types without modifying existing client code.

This Factory Pattern example demonstrates the creation of burgers using the Factory design pattern. 

The implementation includes:

#### Classes

- **`burger`**: Interface declaring methods that concrete burgers must implement.
- **`cheese_burger`**: Concrete class implementing the `burger` interface for cheeseburgers.
- **`veggie_burger`**: Concrete class implementing the `burger` interface for veggieburgers.
- **`burger_factory`**: Interface for creating burgers, declaring a method to create burgers.
- **`cheese_burger_factory`**: Concrete factory creating instances of `cheese_burger`.
- **`veggie_burger_factory`**: Concrete factory creating instances of `veggie_burger`.

## Example Usage

The pattern allows creating different types of burgers through factory objects. For instance:

```cpp
// Create a factory for cheeseburgers
auto cheese_burger_factory = std::make_shared<factory_pattern_example::cheese_burger_factory>();
auto cheese_burger = cheese_burger_factory->create_burger();
cheese_burger->prepare();
cheese_burger->cook();
cheese_burger->serve();
// Create a factory for veggieburgers
auto veggie_burger_factory = std::make_shared<factory_pattern_example::veggie_burger_factory>();
auto veggie_burger = veggie_burger_factory->create_burger();
veggie_burger->prepare();
veggie_burger->cook();
veggie_burger->serve();
```

# Builder Pattern Example

## Overview

Builder is a creative design pattern that allows you to build complex objects step by step. 
This pattern allows you to create different types and representations of an object using the same construction code.
The example here illustrates the Builder pattern in the context of creating customized computers, specifically gaming and office computers.

## Classes

### `computer` Class

- The `computer` class embodies the product to be constructed. It provides methods to set crucial components like the CPU, RAM, and storage. Additionally, it includes a method to display the computer's configuration.

### `computer_builder` Interface

- The `computer_builder` interface defines the methods that concrete builders must implement. These methods include building the CPU, RAM, storage, and retrieving the constructed computer.

### `gaming_computer_builder` Class

- The `gaming_computer_builder` class is a concrete builder tailored for gaming computers. It implements methods to construct a gaming computer.

### `office_computer_builder` Class

- The `office_computer_builder` class is another concrete builder designed for office computers. It implements methods to build a standard office computer.

### `computer_director` Class

- The `computer_director` class orchestrates the construction process using a builder. It contains a method to construct a computer by invoking the builder's methods to assemble the CPU, RAM, and storage components.

## Example Usage

```cpp
// Create a gaming computer
builder_pattern::gaming_computer_builder gaming_builder;
builder_pattern::computer_director director;
builder_pattern::computer gaming_computer = director.construct(gaming_builder);

// Create an office computer
builder_pattern::office_computer_builder office_builder;
builder_pattern::computer office_computer = director.construct(office_builder);

// Display the configurations
std::cout << "Gaming Computer Configuration:\n";
gaming_computer.show_info();

std::cout << "\nOffice Computer Configuration:\n";
office_computer.show_info();
```

### Prototype Pattern Example

## Overview

This example demonstrates the Prototype pattern, in which new objects are created by copying an existing object.

Here, we have a `prototype_pattern_example` showcasing the use of the Prototype pattern with shapes.

## Prototype Pattern Classes

### Prototype (Shape): `shape`

The `shape` class defines the prototype for various shapes. It declares the `clone_shape()` method to create a new instance of the shape.

### Concrete Prototypes: `circle` and `square`

The `circle` and `square` classes are concrete implementations of the `shape` prototype. They provide their own `clone_shape()` and `draw()` methods.

## Example Usage

```cpp
    // Create prototypes
    auto circle_prototype = std::make_unique<prototype_pattern_example::circle>();
    auto square_prototype = std::make_unique<prototype_pattern_example::square>();

    // Clone shapes
    auto copy_of_circle = circle_prototype->clone_shape();
    auto copy_of_square = square_prototype->clone_shape();

    // Draw the cloned shapes
    copy_of_circle->draw();
    copy_of_square->draw();

