#include "GolfCart.h"
#include <iostream>

using namespace std;

GolfCart::GolfCart(const string& make, const string& model, const int level, const string& department, int speed) : Vehicle(make, model, level){
	departmentName = department;
	maxSpeed = speed;
}

void GolfCart::describe()const {
	Vehicle::describe();

	cout << "Department: "
		<< departmentName 
		<< endl
		<< "Max Speed: "
		<< maxSpeed << " mph"
		<< endl;
}
void GolfCart::refuel(){
	fuelLevel += 50;
	if (fuelLevel > 100)
		fuelLevel = 100;

	cout << "Golf Cart refueled to " << fuelLevel 
		<< "%" << endl;
}