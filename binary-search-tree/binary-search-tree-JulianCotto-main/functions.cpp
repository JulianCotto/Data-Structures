/*********************
Name: Julian Cotto
Assignment 8
Purpose: This program will create a binary tree and will allow the user to
         insert, delete, and search for a node. It will also print the tree
         in order, pre order, and post order.
**********************/

#include "functions.h"

// do not modify this function
int random_range(int min, int max) {
    //returns a random number between min and max inclusive
    return (std::rand() % (max - min + 1)) +min;
}
// you may add more functions here if you need them
DataNode* minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
