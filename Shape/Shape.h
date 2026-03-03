#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    double getArea() const;
    void display() const;
    Shape(const std::string& color, double x)
     : color(color), x(x) {}
protected:
    std::string color;
    double x;
};

#endif /* SHAPE_H */