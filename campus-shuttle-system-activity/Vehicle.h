#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
	protected:
		std::string make, model;
		int fuelLevel;
	public:
		Vehicle(const std::string&, const std::string&, const int);
		void describe() const;
		void refuel();
};
#endif