/*********************
Name: Julian Cotto
Assignment 4 - Int Stack
Purpose: header file for stack.cpp
**********************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define SIZE 10

/* <iostream> is included only for programmer debugging
 * should NOT be part of the completed version
 * *** DO NOT LEAVE THIS IN PRODUCTION CODE *** */
#include <iostream>

class Stack
{
    public:
        Stack(); // constructor
	~Stack(); // destructor

        /* Note: normally peek and pop should have identical in interfaces. They are only
        * different here to demonstrate alternate solutions. In a real solution, pop()
        * and peek() should have identical interfaces.
        */
	int pop();
	bool peek(int*);
        bool push(int);
        bool isEmpty();

        // this is a programmer debug routine
        // DO NOT LEAVE THIS IN PRODUCTION CODE
	void dumpStack();

    private:
        int top; // do not initialize here, that's what the constructor is for
        int stack[SIZE]; // stack array
};

#endif //STACK_STACK_H
