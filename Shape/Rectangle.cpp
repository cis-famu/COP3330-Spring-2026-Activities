#include "Rectangle.h"

using namespace std;

double Rectangle::getArea() const {
    return width * height;
}
void Rectangle::display()const{
    //cout << "The rectangle is: " << color << endl;
    Shape::display(); // Call the base class display function to show the color
    cout << "The width is: " << width << endl;
    cout << "The height is: " << height << endl;
    //cout << "The area is: " << getArea() << endl;
} 