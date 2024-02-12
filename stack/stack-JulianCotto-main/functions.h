/*********************
Name: Julian Cotto
Assignment 5 - Stacks
Purpose: header file for functions.cpp
**********************/

#ifndef STACKS_FUNCTIONS_H
#define STACKS_FUNCTIONS_H

#define MAXSTRSIZE 8

#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time */
#include <string>     /* string */
#include <cctype>

using std::isdigit;
using std::string;

void rand_string(std::string*);
void verifyInput(int, char**, int*, bool*);
void errorCases(int);
#endif /* STACKS_FUNCTIONS_H */
