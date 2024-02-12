/*********************
Name: Julian Cotto
Assignment 7 - Hash Tables
Purpose: source file for linkedlist.h
**********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, string *data) {
    bool result = true;
    if (id > 0) {
        if (!head) {
            head = new Node{id, *data};
        } else {
            Node *current = head;
            bool found = false;
            while (current && !found) {
                if (current->data.id == id || current->data.data == *data) {
                    result = false;
                    found = true;
                } else if (!current->next || current->next->data.id > id) {
                    found = true;
                } else {
                    current = current->next;
                }
            }
            if (result) {
                Node *newNode = new Node{id, *data};
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
            }
        }
    } else {
        result = false;
    }
    return result;
}

bool LinkedList::deleteNode(int id) {
    bool result = false;
    if (head) {
        Node *current = head;
        bool found = false;
        while (current && !found) {
            if (current->data.id == id) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                if (current == head) {
                    head = current->next;
                }
                delete current;
                result = true;
                found = true;
            } else {
                current = current->next;
            }
        }
    }
    return result;
}

bool LinkedList::getNode(int id, Data *data) {
    bool result = false;
    if (head) {
        Node *current = head;
        bool found = false;
        while (current && !found) {
            if (current->data.id == id) {
                *data = current->data;
                result = true;
                found = true;
            } else {
                current = current->next;
            }
        }
    }
    return result;
}

void LinkedList::printList(bool reverse) {
    if (!head) {
        return;
    }
    if (reverse) {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        while (current) {
            cout << "(" << current->data.id << ": " << current->data.data << ")" << endl;
            current = current->prev;
        }
    } else {
        Node *current = head;
        while (current) {
            cout << "(" << current->data.id << ": " << current->data.data << ")" << endl;
            current = current->next;
        }
    }
}

int LinkedList::getCount() {
    int count = 0;
    Node *current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool LinkedList::clearList() {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    return true;
}

bool LinkedList::exists(int id) {
    bool result = false;
    Node *current = head;
    bool found = false;
    while (current && !found) {
        if (current->data.id == id) {
            result = true;
            found = true;
        } else {
            current = current->next;
        }
    }
    return result;
}
