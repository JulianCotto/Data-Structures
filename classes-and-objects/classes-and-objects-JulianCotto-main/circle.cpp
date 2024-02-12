/*********************
Name: Julian Cotto
Classes & Objects Refresher
Purpose: class definitions for circle class
**********************/

#include "circle.h"

Circle::Circle() {
    setRadius(MIN);
}

Circle::Circle(double r) {
    setRadius(r);
}

Circle::~Circle() {
}

double Circle::getRadius() {
    return radius;
}

double Circle::getArea() {
    return radius * radius * 3.14159;
}

double Circle::getCircumference() {
    return 2 * 3.14159 * radius;
}

void Circle::setRadius(double r) {
    if (r > MIN) {
        radius = r;
    } else {
        radius = MIN;
    }
}
