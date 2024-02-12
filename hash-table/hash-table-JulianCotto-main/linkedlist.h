/*********************
Name: Julian Cotto
Assignment 7 - Hash Tables
Purpose: source file for linkedlist.h
**********************/

#include "data.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{

public:
    LinkedList();
    ~LinkedList();
    bool addNode(int, string*); // accepts id and data and inserts to the list in order
    bool deleteNode(int); // accepts an id and deletes the node
    bool getNode(int, Data*); // retrieves the data from a node with given id
    void printList(bool = false); // prints forward(default) or backward <- encapsulate within ADT
    int getCount(); // prints count dynamically
    bool clearList(); // deallocates all nodes and sets head to NULL
    bool exists(int); // tests for the existense of a node based on a given id

private:
    Node* head;
};
#endif /* LINKEDLIST_H */
