#include "Shape.h"
using namespace std;

double Shape::getArea() const {
    return x * x;
}
void Shape::display() const {
    cout << "The shape is: " << color << endl;
    cout << "The area is: " << getArea() << endl;
}