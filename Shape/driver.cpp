#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Shape shape("Red");
    shape.display();

    Circle circle( 5.0, "Blue");
    circle.display();

    Rectangle rectangle(4.0, 6.0, "Green");
    rectangle.display();

    return 0;
}