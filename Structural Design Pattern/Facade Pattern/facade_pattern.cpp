#include "../../Includes.hpp"

namespace facade_pattern_example
{
	void car_facade::start_car()
	{
		engine::start();
		lights::turn_on();
		fuel_system::pump_fuel();
		std::cout << "Car started and ready to go!\n";
	}

	void car_facade::stop_car()
	{
		engine::stop();
		lights::turn_off();
		fuel_system::stop_pumping_fuel();
		std::cout << "Car stopped.\n";
	}

	void engine::start()
	{
		std::cout << "Engine started.\n";
	}

	void engine::stop()
	{
		std::cout << "Engine stopped.\n";
	}

	void lights::turn_on()
	{
		std::cout << "Lights turned on.\n";
	}

	void lights::turn_off()
	{
		std::cout << "Lights turned off.\n";
	}

	void fuel_system::pump_fuel()
	{
		std::cout << "Fuel pumped.\n";
	}

	void fuel_system::stop_pumping_fuel()
	{
		std::cout << "Fuel stopped pumping.\n";
	}
}
