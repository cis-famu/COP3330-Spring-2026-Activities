#ifndef GULF_CART_H
#define GULF_CART_H

#include "Vehicle.h"

class GulfCart : public Vehicle {

	public:
		GulfCart(const std::string&, const std::string&, const int, const std::string&, const int);
		void describe()const;
		void refuel();
	
	private:
		std::string departmentName;
		int maxSpeed;
};
#endif