#ifndef MAINTENANCE_TRUCK_H
#define MAINTENANCE_TRUCK_H

#include "Vehicle.h"

class MaintenanceTruck : public Vehicle {

	public: 
		MaintenanceTruck(
			const std::string&,
			const std::string&,
			const int,
			const std::string&,
			const int );
		void describe()const;

	private:
		std::string cargoDescription;
		int cargoWeight;


};

#endif