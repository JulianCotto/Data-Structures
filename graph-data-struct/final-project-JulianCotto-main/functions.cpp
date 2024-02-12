/*********************
Name: Julian Cotto
Final Project - Graphs
Purpose: source file for functions.h
**********************/

#include "functions.h"

vector<int> generateRandomInts(int n) {
    std::vector<int> result;
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        result.push_back(rand() % 90000 + 10000);
    }
    return result;
}

vector<string> generateRandomStrings(int n) {
    vector<string> result;
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        std::string str;
        for (int j = 0; j < 5; j++) {
            str += 'a' + rand() % 26;
        }
        result.push_back(str);
    }
    return result;
}
