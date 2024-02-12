/*********************
Name: Julian Cotto
Classes & Objects Refresher
Purpose: print definitions for circle and sphere class
**********************/

#include "functions.h"

void printCircle(Circle *myCircle) {
    std::cout << "       Circle Radius: " << myCircle->getRadius() << std::endl;
    std::cout << "         Circle Area: " << myCircle->getArea() << std::endl;
    std::cout << "Circle Circumference: " << myCircle->getCircumference() << std::endl;
    std::cout << std::endl;
}

void printSphere(Sphere *mySphere) {
    std::cout << "      Sphere Radius: " << mySphere->getRadius() << std::endl;
    std::cout << "      Sphere Volume: "<<  mySphere->getVolume() << std::endl;
    std::cout << "Sphere Surface Area: " << mySphere->getSurfaceArea() << std::endl;
    std::cout << std::endl;
}


