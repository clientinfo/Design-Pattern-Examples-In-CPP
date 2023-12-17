#pragma once

namespace facade_pattern_example
{
	/**
	 * @brief Subsystem representing the car engine.
	 */
	class engine
	{
	public:
		/**
		 * @brief Start the car engine.
		 */
		static void start();

		/**
		 * @brief Stop the car engine.
		 */
		static void stop();
	};

	/**
	 * @brief Subsystem representing the car lights.
	 */
	class lights
	{
	public:
		/**
		 * @brief Turn on the car lights.
		 */
		static void turn_on();

		/**
		 * @brief Turn off the car lights.
		 */
		static void turn_off();
	};

	/**
	 * @brief Subsystem representing the car fuel system.
	 */
	class fuel_system
	{
	public:
		/**
		 * @brief Pump fuel for the car.
		 */
		static void pump_fuel();

		/**
		 * @brief Stop pumping fuel for the car.
		 */
		static void stop_pumping_fuel();
	};

	/**
	 * @brief Facade providing a simplified interface to control the car subsystems.
	 */
	class car_facade
	{
	public:
		/**
		 * @brief Start the car using the Car Facade.
		 *
		 * This method orchestrates the subsystems to start the car.
		 */
		static void start_car();

		/**
		 * @brief Stop the car using the Car Facade.
		 *
		 * This method orchestrates the subsystems to stop the car.
		 */
		static void stop_car();
	};
}
