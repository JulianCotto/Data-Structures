/*********************
Name: Julian Cotto
Classes & Objects Refresher
Purpose: Header file for sphere class
**********************/

#ifndef CLASSES_SPHERE_H
#define CLASSES_SPHERE_H

#include "circle.h"

class Sphere: public Circle {

    public:
        Sphere();
        explicit Sphere(double);
        ~Sphere();

        double getRadius();
        double getVolume();
        double getSurfaceArea();

        void setRadius(double r);
};


#endif //CLASSES_SPHERE_H
