#ifndef GOLF_CART_H
#define GOLF_CART_H

#include "Vehicle.h"

class GolfCart : public Vehicle {

	public:
		GolfCart(const std::string&, const std::string&, const int, const std::string&, const int);
		void describe()const;
		void refuel();
	
	private:
		std::string departmentName;
		int maxSpeed;
};
#endif