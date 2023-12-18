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

## Usage

To use the Singleton pattern in your program, follow these steps:

1. Call `get_instance()` to obtain the singleton instance.
2. Use the obtained instance to access or modify the class's functionalities.
3. Optionally, call `print_text_in_console(const std::string& arg_text)` to print text to the console.

## Example

```cpp
#include "singleton_pattern.hpp"

int main() {
    // Get the singleton instance
    auto singleton_instance = singleton_pattern_example::singleton_pattern::get_instance();

    // Print text using the singleton instance
    singleton_instance->print_text_in_console("Hello, Singleton!");

    return 0;
}
```

# Builder Pattern Example

Builder is a creative design pattern that allows you to build complex objects step by step. 
This pattern allows you to create different types and representations of an object using the same construction code.
The example here illustrates the Builder pattern in the context of creating customized computers, specifically gaming and office computers.

## Classes

### `computer` Class

The `computer` class embodies the product to be constructed. It provides methods to set crucial components like the CPU, RAM, and storage. Additionally, it includes a method to display the computer's configuration.

### `computer_builder` Interface

The `computer_builder` interface defines the methods that concrete builders must implement. These methods include building the CPU, RAM, storage, and retrieving the constructed computer.

### `gaming_computer_builder` Class

The `gaming_computer_builder` class is a concrete builder tailored for gaming computers. It implements methods to construct a gaming computer.

### `office_computer_builder` Class

The `office_computer_builder` class is another concrete builder designed for office computers. It implements methods to build a standard office computer.

### `computer_director` Class

The `computer_director` class orchestrates the construction process using a builder. It contains a method to construct a computer by invoking the builder's methods to assemble the CPU, RAM, and storage components.

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
This example demonstrates the creation of a gaming computer and an office computer using the Builder pattern.
You can tailor the computer's configuration by choosing different builders, such as gaming_computer_builder and office_computer_builder.

