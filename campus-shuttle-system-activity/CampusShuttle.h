#ifndef CAMPUS_SHUTTLE_H
#define CAMPUS_SHUTTLE_H

#include "Vehicle.h"

class CampusShuttle: public Vehicle {

	private:
		int maxCapacity;
		std::string routeName;

	public:
		CampusShuttle(const std::string& make_, const std::string& model_,
		int fuelLevel, 
		const std::string& routeName, 
		int maxCapacity) : Vehicle(make_, model_, fuelLevel) {
			this->maxCapacity = maxCapacity;
			this->routeName = routeName;
		}
	
		void describe() const;
		void refuel();
};
#endif