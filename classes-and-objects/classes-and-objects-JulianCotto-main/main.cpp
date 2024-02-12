/*********************
Name: Julian Cotto
Classes & Objects Refresher
Purpose: Main file for classes and objects refresher
**********************/

#include "main.h"

int main(int argc, char** argv) {


    Circle myCircle1;
    Circle myCircle2(10);

    Sphere mySphere1;
    Sphere mySphere2(10);

    std::cout << "Initialized with default constructor" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    printCircle(&myCircle1);

    std::cout << "Initialized with explicit constructor" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    printCircle(&myCircle2);

    std::cout << "Initialized with default constructor" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    printSphere(&mySphere1);

    std::cout << "Initialized with explicit constructor" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    printSphere(&mySphere2);

    return 0;
}