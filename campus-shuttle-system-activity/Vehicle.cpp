#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(const string& make, 
	const string& model, const int level) {
	this->make = make;
	this->model = model;
	
	if(level >= 0 && level <= 100)
		fuelLevel = level;
	else
		fuelLevel = 0;
}
void Vehicle::describe() const {
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Fuel Level: " << fuelLevel << "%" << endl;
}
void Vehicle::refuel() {
	fuelLevel = 100;
	cout << "Vehicle refueled to 100%" << endl;
}