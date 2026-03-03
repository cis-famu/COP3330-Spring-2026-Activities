#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h, string c): Shape(c, w) {
        width = w;
        height = h;
    }
    double getArea() const;
    void display() const;
};
#endif /* RECTANGLE_H */