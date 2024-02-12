/*********************
Name: Julian Cotto
Final Project - Graphs
Purpose: graph header file
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <queue>
#include <stack>


using std::vector;
using std::pair;
using std::string;
using std::runtime_error;
using std::cout;
using std::endl;
using std::queue;
using std::stack;


class Graph {
public:
    Graph();
    ~Graph();

    bool addEdge(int, int, Data&);
    bool removeEdge(int, int);
    bool addVertex(int);
    bool removeVertex(int);
    bool isVertex(int);
    bool isEdge(int, int);

    int getVertexCount();
    int getEdgeCount();

    void depthFirstTraversal(int);
    void breadthFirstTraversal(int);
    void printAllEdgeData();
    void printGraph();
    void clearGraph();

    Data getEdgeData(int, int);

    Graph getDFST(int);
    Graph getBFST(int);
protected:
    void dfsUtil(int, vector<bool>&, Graph &dfst);
private:
    vector<vector<pair<int, Data>>> adjList;

};

#endif /* GRAPH_H */
