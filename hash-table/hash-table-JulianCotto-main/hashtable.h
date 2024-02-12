/*********************
Name: Julian Cotto
Assignment 7 - Hash Tables
Purpose: source file for linkedlist.h
**********************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"

#define HASHTABLESIZE 15

class HashTable {
public:
    HashTable();
    ~HashTable();
    bool insertEntry(int id, string *data);
    string getData(int id);
    bool removeEntry(int id);
    int getCount();
    void printTable();

private:
    int hash(int id);
    LinkedList table[HASHTABLESIZE];
    int count;
};

#endif /* HASHTABLE_H */
