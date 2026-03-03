#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r, string c) : Shape(c, r) {
        //x = r; // Assuming x is used to store the radius in the base class
        radius = r;
    }
    double getArea() const;
    void display() const;
};
#endif 