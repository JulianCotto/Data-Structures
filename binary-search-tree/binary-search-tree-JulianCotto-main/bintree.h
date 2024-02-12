/*********************
Name: Julian Cotto
Assignment 8
Purpose: This program will create a binary tree and will allow the user to
         insert, delete, and search for a node. It will also print the tree
         in order, pre order, and post order.
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "data.h"
#include "functions.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

class BinTree {
    public:
        BinTree();
        ~BinTree();

        bool isEmpty();
        int getCount();
        void displayTree();
        bool getRootData(Data*);

        void displayPreOrder();
        void displayPostOrder();
        void displayInOrder();
        void clear();
        bool addNode(int, const string*);
        bool removeNode(int);
        bool getNode(Data*, int);
        bool contains(int);
        int getHeight();

    private:
        DataNode *root;
        int count;

        void displayPreOrder(DataNode*);
        void displayPostOrder(DataNode*);
        void displayInOrder(DataNode*);
        void clear(DataNode*);
        bool addNode(DataNode*, DataNode**);
        DataNode* removeNode(int, DataNode*);
        bool getNode(Data*, int, DataNode*);
        bool contains(int, DataNode*);
        int getHeight(DataNode*);
};
#endif /* BINTREE_BINTREE_H */
