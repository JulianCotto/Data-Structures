/*********************
Name: Julian Cotto
Assignment 5 - Stacks
Purpose: source file for functions.h containing input verification, random string generation, and error handling
**********************/

#include <iostream>
#include "functions.h"

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;

    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to pass in string
    *str = buffer;

    // clean up
    delete[] buffer;
}

void verifyInput(int argc, char **argv, int *errorPtr, bool *validInputPtr){
    *validInputPtr = false;
    if(argc == 1){
        *errorPtr = 1;
        *validInputPtr = false;
    }else if(argc != 2){
        *errorPtr = 2;
        *validInputPtr = false;
    }else{
        string arg = argv[1];
        for (char c : arg) {
            if (!isdigit(c)) {
                *errorPtr = 3;
                *validInputPtr = false;
            } else {
                *errorPtr = 0;
                *validInputPtr = true;
            }
        }
    }
}

void errorCases(int errorCode) {

    switch (errorCode) {
        case 0:
            std::cout << "No error" << std::endl;
            break;
        case 1:
            std::cout << "Error | Arguments Expected: 2 | Arguments Received: 1" << std::endl;
            break;
        case 2:
            std::cout << "Error | Unexpected Arguments | Arguments Expected: 2" << std::endl;
            break;
        case 3:
            std::cout << "Type Error | Program Only Accepts Integer Arguments" << std::endl;
            break;
        case 4:
            std::cout << "Type Error | Stack::push() Only Accepts Positive Integers As First Argument" << std::endl;
            break;
        case 5:
            std::cout << "Type Error | Stack::push() Requires String Argument" << std::endl;
            break;
        case 6:
            std::cout << "Stack Overflow | Stack is Full" << std::endl;
            break;
        case 7:
            std::cout << "Undefined Issue with Stack::push()" << std::endl;
            break;
        case 8:
            std::cout << "Type Error: Cannot push() empty string to stack" << std::endl;
            break;
        case 9:
            std::cout << "Stack Underflow | Stack is Empty" << std::endl;
            break;
        default:
            std::cout << "Error: Invalid argument" << std::endl;
    }
}
