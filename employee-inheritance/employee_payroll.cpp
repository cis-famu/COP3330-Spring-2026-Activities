#include <string>
#include <iostream>
using namespace std;

// Base class representing a generic employee
class Employee {
  public:

    // Virtual function allows derived classes to override wage calculation.
    // Default implementation assumes overtime: 40 hrs at base rate,
    // anything beyond 40 hrs is paid at 1.5x (time-and-a-half).
    virtual double calcWage() {
        return 40 * rate + ((hours - 40) * rate * 1.5);
    }

    // NOT virtual — this means the version called depends on the
    // *declared type* of the pointer/variable, not the actual object type.
    // Internally calls calcWage(), which IS virtual, so wage calculation
    // will still resolve to the correct overridden version at runtime.
    void printPayStub() {
        cout << "Name : " << name << endl
             << "Hours: " << hours << endl
             << "Rate: "  << rate  << endl
             << "Salary: " << calcWage() << endl; // virtual dispatch happens here
    }

  protected:
    // Accessible to this class and any derived classes, but not outside
    string name;
    double hours;
    double rate;
};

// HourlyEmployee inherits all members of Employee
class HourlyEmployee : public Employee {
  private:
    string departmentName; // unique to hourly employees

  public:
    // Constructor initializes all fields, including the inherited protected ones
    HourlyEmployee(string n, double h, double r, string d) {
        name   = n;
        hours  = h;
        rate   = r;
        departmentName = d;
    }

    // Overrides printPayStub() for HourlyEmployee objects.
    // This version prepends department info, then delegates
    // the rest of the output to the base class version.
    // NOTE: This override has no effect when called through an Employee* pointer
    // because printPayStub() is NOT virtual in the base class.
    void printPayStub() {
        cout << "Deparment: " << departmentName << endl;
        Employee::printPayStub(); // explicitly call base class version
    }
};

// SalariedEmployee inherits from Employee but uses a fixed salary model
class SalariedEmployee : public Employee {
  public:
    // Constructor sets hours to 40 as a placeholder (not used in wage calc)
    SalariedEmployee(string n, double r) {
        name  = n;
        rate  = r;
        hours = 40;
    }

    // Overrides calcWage() to return the fixed salary directly.
    // The 'override' keyword confirms this is intentionally overriding
    // a virtual function (compiler will error if it doesn't match).
    double calcWage() override {
        return rate; // rate stores the flat salary amount
    }
};

int main() {

    // emp1: Employee pointer holding a HourlyEmployee object (polymorphism)
    Employee * emp1 = new HourlyEmployee("John", 43, 34.98, "IT");

    // emp2: Employee pointer holding a SalariedEmployee object (polymorphism)
    Employee * emp2 = new SalariedEmployee("Smith", 5000);

    // Calls Employee::printPayStub() — NOT HourlyEmployee::printPayStub()
    // because printPayStub is non-virtual (resolved at compile time by pointer type).
    // However, calcWage() inside IS virtual, so HourlyEmployee's inherited
    // calcWage() (from Employee) runs correctly at runtime.
    emp1->printPayStub();

    cout << endl
         << "-----------------------------" << endl;


    // Calls Employee::printPayStub(); calcWage() dispatches to
    // SalariedEmployee::calcWage() at runtime, returning 5000.
    emp2->printPayStub();

    cout << endl
         << "-----------------------------" << endl;

    // emp3 is declared as an actual HourlyEmployee (not a base class pointer).
    // The compiler knows the exact type at compile time, so
    // HourlyEmployee::printPayStub() is called directly — department IS printed.
    HourlyEmployee emp3("Kevin", 43, 34.98, "Sales");
    emp3.printPayStub();

    return 0;
}