/*********************
Name: Julian Cotto
Classes & Objects Refresher
Purpose: class definitions for sphere class
**********************/
#include "sphere.h"

Sphere::Sphere() {
    setRadius(MIN);
}

Sphere::Sphere(double r) {
    setRadius(r);
}

Sphere::~Sphere() {
}

double Sphere::getRadius() {
    return radius;
}

double Sphere::getVolume() {
    return 4.0/3.0 * 3.14159 * getRadius() * getRadius() * getRadius();
}

double Sphere::getSurfaceArea() {
    return 4 * 3.14159 * getRadius() * getRadius();
}

void Sphere::setRadius(double r) {
    if (r > MIN) {
        radius = r;
    } else {
        radius = MIN;
    }
}
