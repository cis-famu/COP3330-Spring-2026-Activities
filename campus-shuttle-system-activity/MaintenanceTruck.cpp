#include "MaintenanceTruck.h"
#include <iostream>

using namespace std;

MaintenanceTruck::MaintenanceTruck(
	const std::string& make,
	const std::string& model,
	const int fuelLevel,
	const std::string& desc,
	const int weight)
	: Vehicle(make, model, fuelLevel) {

		cargoDescription = desc;
		cargoWeight = weight;
	}
void MaintenanceTruck::describe()const {

	Vehicle::describe();

	cout << "Cargo Description: "
		<< cargoDescription
		<< endl 
		<< "Cargo Weight: "
		<< cargoWeight 
		<< " lbs" << endl;
}
