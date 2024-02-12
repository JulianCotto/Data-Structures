/*********************
Name: Julian Cotto
Assignment 5 - Stacks
Purpose: source file for stack.h with stack class functions
**********************/

#include "stack.h"

Stack::Stack(int stackSize){
    this->top = -1;
    if(stackSize > 0 && stackSize < 2){
        stackSize = 2;
    }
    this->size = stackSize;
    this->stack = new Data*[size];
    for(int i = 0; i < size; i++){
        stack[i] = nullptr;
    }
};

Stack::~Stack(){
    for (int i = 0; i <= top; i++) {
        delete stack[i];
    }
    delete[] stack;
}


bool Stack::push(int id, string* strTemp, int* errorPtr){
    bool pushed = false;
    if(intIntegrity(id, strTemp, errorPtr)){
        if (top < size - 1) {
            Data* d = new Data;
            d->id = id;
            d->information = *strTemp;
            stack[++top] = d;
            pushed = true;
        }else{
            *errorPtr = 6;
        }
    }
    return pushed;
}

bool Stack::pop(Data *d, int* errorPtr){
    bool popped = false;
    if(!isEmpty()) {
        d->id = stack[top]->id;
        d->information = stack[top]->information;
        delete stack[top];
        stack[top--] = nullptr;
        popped = true;
        *errorPtr = 0;
    }else{
        *errorPtr = 9;
    }
    return popped;
}

bool Stack::peek(Data *d, int* errorPtr){
    bool peeked = false;
    if(!isEmpty()) {
        d->id = stack[top]->id;
        d->information = stack[top]->information;
        peeked = true;
        *errorPtr = 0;
    }else{
        d->id = -1;
        d->information = "";
        *errorPtr = 9;
    }
    return peeked;
};

bool Stack::isEmpty() {
    return top < 0;
}

bool Stack::intIntegrity(int id, string* str, int* errorPtr){
    bool validInput = false;
    bool validId = false;
    bool validStr = false;

    if(id >= 0){
        validId = true;
    }
    if(!str->empty()){
        validStr = true;
    }
    if(!validId){
        *errorPtr = 4;
    }
    if(!validStr){
        *errorPtr = 5;
    }
    if(validId && validStr){
        validInput = true;
        *errorPtr = 0;
    }
    return validInput;
}
