/*********************
Name: Julian Cotto
Assignment 8
Purpose: This program will create a binary tree and will allow the user to
         insert, delete, and search for a node. It will also print the tree
         in order, pre order, and post order.
**********************/

#ifndef BINTREE_FUNCTIONS_H
#define BINTREE_FUNCTIONS_H

#include <stdlib.h> /* rand */
#include <bintree.h>

// do not modify this prototype
int random_range(int, int);

// you may add more prototypes here if you need them
DataNode* minValueNode(DataNode*);

#endif /* BINTREE_HEADER_H */
