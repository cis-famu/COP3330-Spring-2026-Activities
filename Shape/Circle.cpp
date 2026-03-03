#include "Circle.h"
#include <cmath> //Required for M_PI constant

using namespace std;

double Circle::getArea() const {
    return M_PI * radius * radius; //M_PI is a constant defined in cmath that represents the value of pi
}
void Circle::display() {
    cout << "The circle is: " << color << endl;
    cout << "The radius is: " << radius << endl;
    cout << "The area is: " << getArea() << endl;
}