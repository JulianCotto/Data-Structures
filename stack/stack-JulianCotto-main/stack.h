/*********************
Name: Julian Cotto
Assignment 5 - Stacks
Purpose: header file for stack.cpp
**********************/

#ifndef STACK_H
#define STACK_H

#define MULTIPLIER 3 // used to test overflow and underflow
#define NARROW .35 // percent of the stack for a narrow band
#define RANDOM_MULTIPLIER 25
#define CHOICES 6 // used to pick random operations
#define MAX_INT 100000 // random ints to push, 1 - 100000

#include <iostream>
#include "data.h"

using std::cout;
using std::endl;

class Stack {

public:
    Stack(int);
    ~Stack();

    bool push(int, string*, int*);
    bool pop(Data*, int*);
    bool peek(Data*, int*);
    bool isEmpty();
    bool intIntegrity(int, string*, int*);

private:
    int top;
    int size;
    Data **stack;
};

#endif //STACK_H
