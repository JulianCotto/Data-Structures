/*********************
Name: Julian Cotto
Assignment 4 - Int Stack
Purpose: contains class functions for stack class/data structure 
**********************/

#include "stack.h"

Stack::Stack() {
        /* the 'this' designation is optional. use it where there
        * is ambiguity or just to be complete and precise. here it
        * is used just to show usage for demonstration purposes.
        */
	this->top = -1;
}

Stack::~Stack() {
	// there is nothing to do to clean up for this object,
        // so this is blank
}

bool Stack::push(int i) {
	bool pushed = false;
	if (top < SIZE - 1) {
		stack[++top] = i;
		pushed = true;
	}
	return pushed;
}

int Stack::pop()
{
    if (top < 0)
    {
	    throw -1; // throw an int because we cannot return one
    } // no else is needed because throw causes an immediate halt in execution
    return stack[top--];
}


/* normally peek and pop should have identical function headers.
 * this is only different to demonstrate an alternate solution. */
bool Stack::peek(int *ret)
{
    bool popped = false;

    if (top > -1)
    {
        *ret = stack[top];
    }
    return popped;
}

bool Stack::isEmpty() {
	return top < 0;
}

// this is a programmer debug routine
// DO NOT LEAVE THIS IN PRODUCTION CODE
// this not a routin appropriate for final testing
// it is only for debugging during development
void Stack::dumpStack() {
	std::cout << "dumping whole stack..." << std::endl;
	if (!isEmpty()) {
		for (int i = top; i >= 0; i--)
		{
			std::cout << stack[i] << std::endl;
		}	
	} else {
		std::cout << "\tstack is empty" << std::endl;
	}
	std::cout << std::endl;
}

