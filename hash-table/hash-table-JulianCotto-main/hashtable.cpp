/*********************
Name: Julian Cotto
Assignment 7 - Hash Tables
Purpose: source file for linkedlist.h
**********************/

#include "hashtable.h"

HashTable::HashTable() : count(0) {}

HashTable::~HashTable() {}

int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}

bool HashTable::insertEntry(int id, string *data) {
    bool result = false;
    if (id > 0 && !data->empty()) {
        int index = hash(id);
        result = table[index].addNode(id, data);
        if (result) {
            count++;
        }
    }
    return result;
}

string HashTable::getData(int id) {
    string result = "No Data";
    int index = hash(id);
    Data data;
    if (table[index].getNode(id, &data)) {
        result = data.data;
    }
    return result;
}


bool HashTable::removeEntry(int id) {
    bool result;
    int index = hash(id);
    result = table[index].deleteNode(id);
    if (result) {
        count--;
    }
    return result;
}

int HashTable::getCount() {
    return count;
}

void HashTable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        cout << "Entry " << i << ": ";
        table[i].printList();
        cout << endl;
    }
}
