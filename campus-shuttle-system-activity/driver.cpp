#include "Vehicle.h"
#include "CampusShuttle.h"
#include "GolfCart.h"
#include "MaintenanceTruck.h"
#include <iostream>

using namespace std;

int main() {

	Vehicle vehicle ("Ford", "F-150", 45);


	cout << "===== Vehicle =====" << endl;

	vehicle.describe();
	cout << endl;
	vehicle.refuel();
	cout << endl;
	vehicle.describe();

	cout << endl << endl
		<< "===== Campus Shuttle =====" << endl;

	CampusShuttle shuttle("Ford", "Minivan", 20, "Silver", 15);

	shuttle.describe();
	cout << endl;
	shuttle.refuel();
	cout << endl;
	shuttle.describe();

	cout << endl << endl
		<< "===== Golf Cart =====" << endl;

	GolfCart cart("Yamaha", "Drive Square", 34, "Student Government", 19);

	cart.describe();
	cout << endl;
	cart.refuel();
	cout << endl;
	cart.describe();

	cout << endl << endl
		<< "===== Maintenance Truck =====" << endl;

	MaintenanceTruck truck("Toyota", "4Runner", 67, "Paint", 35);

	truck.describe();
	cout << endl;
	truck.refuel();
	cout << endl;
	truck.describe();

	return 0;
}