/*********************
Name: Julian Cotto
Classes & Objects Refresher
Purpose: Header file for circle class
**********************/

#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

#define MIN 0

class Circle {
    public:
        Circle();
        Circle(double);

        ~Circle();

        double getRadius();
        double getArea();
        double getCircumference();

        void setRadius(double);

    protected:
        double radius;
};


#endif //CLASSES_CIRCLE_H
