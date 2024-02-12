/*********************
Name: Julian Cotto
Assignment 8
Purpose: This program will create a binary tree and will allow the user to
         insert, delete, and search for a node. It will also print the tree
         in order, pre order, and post order.
**********************/

#include "bintree.h"

BinTree::BinTree() {root = nullptr; count = 0;}
BinTree::~BinTree() {clear();}

bool BinTree::isEmpty() {return root == nullptr;}
int BinTree::getCount() {return count;}
void BinTree::displayTree() {

    std::cout << "DISPLAY TREE\n"
                 "==============================================" << std::endl;
    cout << "Tree is " << (isEmpty() ? "" : "NOT ") << "empty" << endl;
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl;
    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl;
    cout << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl;
    cout << "Post-Order Traversal" << endl;
    displayPostOrder();
    std::cout << "==============================================\n" << std::endl;


    return;
}
bool BinTree::getRootData(Data* data) {
    bool result = true;
    if (root == nullptr) {
        data->id = -1;
        result = false;
    }
    else {
        data->id = root->data.id;
        data->information = root->data.information;
    }
    return result;
}

void BinTree::displayPreOrder() {
    displayPreOrder(root);
}
void BinTree::displayPreOrder(DataNode *temproot) {
    if (temproot) {
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->left) {
            displayPreOrder(temproot->left);
        }
        if (temproot->right) {
            displayPreOrder(temproot->right);
        }
    }
}

void BinTree::displayPostOrder() {
    displayPostOrder(root);
}
void BinTree::displayPostOrder(DataNode *temproot) {
    if (temproot) {
        if (temproot->left) {
            displayPostOrder(temproot->left);
        }
        if (temproot->right) {
            displayPostOrder(temproot->right);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }
}

void BinTree::displayInOrder() {
    displayInOrder(root);
}
void BinTree::displayInOrder(DataNode *temproot) {
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }
}

void BinTree::clear() {
    clear(root);
    root = nullptr;
    count = 0;
}
void BinTree::clear(DataNode *node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        node->left = nullptr;
        node->right = nullptr;
    }
    delete node;
}

bool BinTree::addNode(int id, const string *data) {
    bool result = false;
    if (id >= 0 && data != nullptr) {
        DataNode *newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        result = addNode(newNode, &root);
        if (result) {
            count++;
        }
    }
    return result;
}

bool BinTree::addNode(DataNode *newNode, DataNode **root) {
    bool result = false;
    if (!(*root)) {
        *root = newNode;
        result = true;
    } else if (newNode->data.id < (*root)->data.id) {
        result = addNode(newNode, &(*root)->left);
    } else if (newNode->data.id > (*root)->data.id) {
        result = addNode(newNode, &(*root)->right);
    }
    return result;
}

bool BinTree::removeNode(int id) {
    int tempcount = count;
    root = removeNode(id, root);
    return count < tempcount;
}
DataNode* BinTree::removeNode(int id, DataNode* root) {
    DataNode *result = root;
    if (root != NULL) {
        if (id < root->data.id) {
            root->left = removeNode(id, root->left);
        } else if (id > root->data.id) {
            root->right = removeNode(id, root->right);
        } else {
            DataNode *temp;
            if (root->left == NULL) {
                temp = root->right;
                delete root;
                result = temp;
                count--;
            } else if (root->right == NULL) {
                temp = root->left;
                delete root;
                result = temp;
                count--;
            } else {
                temp = minValueNode(root->right);
                root->data.id = temp->data.id;
                root->data.information = temp->data.information;
                root->right = removeNode(temp->data.id, root->right);
            }
        }
    }
    return result;
}

bool BinTree::getNode(Data* data, int id) {
    bool result = false;
    if (id < 0) {
        result = false;
    } else {
        result = getNode(data, id, root);
    }
    return result;
}

bool BinTree::getNode(Data* data, int id, DataNode* node) {
    bool result = false;
    if (node != nullptr) {
        if (id == node->data.id) {
            *data = node->data;
            result = true;
        } else if (id < node->data.id) {
            result = getNode(data, id, node->left);
        } else if (id > node->data.id) {
            result = getNode(data, id, node->right);
        }
    }
    return result;
}

bool BinTree::contains(int id) {
    bool result = false;
    if (id < 0) {
        result = false;
    }
    else {
        result = contains(id, root);
    }
    return result;
}
bool BinTree::contains(int id, DataNode *node) {
    bool result = false;
    if (node != nullptr) {
        if (id == node->data.id) {
            result = true;
        } else if (id < node->data.id) {
            result = contains(id, node->left);
        } else if (id > node->data.id) {
            result = contains(id, node->right);
        }
    }
    return result;
}

int BinTree::getHeight() {
    return getHeight(root);
}
int BinTree::getHeight(DataNode *node) {
    int lh = 0;
    int rh = 0;
    int result = 0;
    if (node) {
        lh = getHeight(node->left);
        rh = getHeight(node->right);
        result = max(lh, rh) + 1;
    }
    return result;
}
