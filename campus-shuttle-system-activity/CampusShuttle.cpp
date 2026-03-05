#include "CampusShuttle.h"
#include <iostream>

using namespace std;


void CampusShuttle::describe() const {
	Vehicle::describe();
	cout << "Max Capacity: " 
		<< maxCapacity << endl
		<< "Route: " << routeName
		<< endl;
		
}
void CampusShuttle::refuel() {
	fuelLevel = 100;
	cout << "Shuttle on " <<  routeName 
		<< " refueled to 100%" 
		<< endl;
}