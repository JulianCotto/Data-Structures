/*********************
Name: Julian Cotto
Final Project - Graphs
Purpose: source file for main.h
**********************/

#include "main.h"
#include <iostream>

int main() {

    // initialize graph
    cout << "\nInitializing Graph Class as graph." << endl;
    Graph graph;
    Graph breadthFirstSpanningTree;
    Graph depthFirstSpanningTree;

    // verify graph after initialization
    cout << "\nGraph Upon Initialization" <<endl;
    graph.printGraph();

    // verify vertexes and edges
    cout << "\nNumber of Vertexes: " << graph.getVertexCount() << endl;
    cout << "Number of Edges: " << graph.getEdgeCount() << endl;

    cout << "\nBegin Testing Graph Base Functions" << endl;
    cout << "Adding 10 Vertexes to Graph" << endl;
    for(int i = 0; i < VERTEXES; i++) {
        cout << "Adding Vertex " << i << endl;
        if(graph.addVertex(i)){
            cout << "Vertex " << i << " Added Successfully" << endl;
        } else {
            cout << "Failed to Add Vertex " << i << endl;
        }
    }

    cout << "\nVerifying All Added Vertexes with isVertex()" << endl;
    for(int i = 0; i < VERTEXES; i++) {
        if (graph.isVertex(i))
        {
            cout << "Vertex " << i << " Successfully Verfied as Vertex" << endl;
        } else {
            cout << i << " Is Not a Vertex" << endl;
        }
    }

    // verify graph is initialized
    cout << "\nGraph After Initialization" << endl;
    graph.printGraph();

    cout << "\nNumber of Vertexes: " << graph.getVertexCount() << endl;
    cout << "Number of Edges: " << graph.getEdgeCount() << endl;

    cout << "\nGenerating Test Data" << endl;
    auto ids = generateRandomInts(TESTDATA);
    auto strings = generateRandomStrings(TESTDATA);

    // Adding 10 edges per vertex
    cout << "\nAdding 10 Edges Per Vertex" << endl;
    int k = 0;
    for (int i = 0; i < VERTEXES; i++) {
        for (int j = 0; j < EDGESBYVERTEX; j++) {
            Data data{ids[k], strings[k]};
            int dest = rand() % (VERTEXES + 1);
            if (graph.addEdge(i, dest, data)) {
                cout << "Edge (" << i << ", " << dest << ") added successfully" << endl;
            } else {
                cout << "Failed to add edge (" << i << ", " << dest << ")" << endl;
            }
            k++;
        }
    }

    cout << "\nVerifying All Edges Added with isEdge()" << endl;
    for (int i = 0; i < VERTEXES; i++) {
        for (int j = 0; j < EDGESBYVERTEX; j++) {
            if (graph.isEdge(i, j)) {
                cout << "Edge (" << i << ", " << j << ") successfully verified as an edge" << endl;
            } else {
                cout << "Edge (" << i << ", " << j << ") is not an edge" << endl;
            }
        }
    }

    cout << "\nVerifying Edge Data with getEdgeData" << endl;
    for (int i = 0; i < VERTEXES; i++) {
        for (int j = 0; j < EDGESBYVERTEX; j++) {
            cout << "Attempting to Get Data From Edge" << endl;
            try{
                Data data = graph.getEdgeData(i, j);
                cout << "Edge (" << i << ", " << j <<  ") identified by: " << " id = " << data.id << ", data = " << data.data << endl;
            }
            catch (runtime_error) {
                cout << "Edge (" << i << ", " << j << ") does not exist" << endl;
            }
        }
    }

    // verify graph after adding edges
    cout << "\nGraph After Adding Edges" << endl;
    graph.printGraph();

    cout << "\nPrinting All Edge Data" << endl;
    graph.printAllEdgeData();

    cout << "\nNumber of Vertexes: " << graph.getVertexCount() << endl;
    cout << "Number of Edges: " << graph.getEdgeCount() << endl;

    cout << "\nPerforming Depth First Traversal of Graph for All Sources" << endl;
    for (int i = 0; i < VERTEXES; i++) {
        cout << "Depth-first traversal for vertex " << i << ": ";
        graph.depthFirstTraversal(i);
        cout << endl;
    }

    cout << "\nPerforming Breadth First Traversal of Graph for All Sources" << endl;
    for (int i = 0; i < VERTEXES; i++) {
        cout << "Breadth-first traversal for vertex " << i << ": ";
        graph.breadthFirstTraversal(i);
        cout << endl;
    }

    cout << "\nExtracting Depth-First Spanning Tree For All Sources" << endl;
    for (int i = 0; i < VERTEXES; i++) {
        depthFirstSpanningTree = graph.getDFST(i);
        cout << "Depth First Spanning Tree For Vertex " << i << endl;
        depthFirstSpanningTree.printGraph();
        cout << "Number of Vertexes: " << depthFirstSpanningTree.getVertexCount() << endl;
        cout << "Number of Edges: " << depthFirstSpanningTree.getEdgeCount() << endl;
        if(depthFirstSpanningTree.getVertexCount() == (depthFirstSpanningTree.getEdgeCount() + 1 )) {
            cout << "Spanning Tree Detected at Source " << i << endl;
        } else {
            cout << "Spanning Tree Not Detected for Source " << i << endl;
        }
        cout << endl;
    }

    cout << "\nClearing and Destroying Depth First Spanning Trees" << endl;
    depthFirstSpanningTree.clearGraph();
    cout << "Number of Vertexes: " << depthFirstSpanningTree.getVertexCount() << endl;
    cout << "Number of Edges: " << depthFirstSpanningTree.getEdgeCount() << endl;

    cout << "\nExtracting Breadth-First Spanning Tree For All Sources" << endl;
    for (int i = 0; i <= VERTEXES; i++) {
        breadthFirstSpanningTree = graph.getBFST(i);
        cout << "Breadth First Spanning Tree For Vertex " << i << endl;
        breadthFirstSpanningTree.printGraph();
        cout << "Number of Vertexes: " << breadthFirstSpanningTree.getVertexCount() << endl;
        cout << "Number of Edges: " << breadthFirstSpanningTree.getEdgeCount() << endl;
        if(breadthFirstSpanningTree.getVertexCount() == (breadthFirstSpanningTree.getEdgeCount() + 1 )) {
            cout << "Spanning Tree Detected at Source " << i << endl;
        } else {
            cout << "Spanning Tree Not Detected for Source " << i << endl;
        }
        cout << endl;
    }

    cout << "\nClearing and Destroying Breadth First Spanning Trees" << endl;
    breadthFirstSpanningTree.clearGraph();
    cout << "Number of Vertexes: " << breadthFirstSpanningTree.getVertexCount() << endl;
    cout << "Number of Edges: " << breadthFirstSpanningTree.getEdgeCount() << endl;

    cout << "\nRemoving Edges and Vertices From Original Graph" << endl;
    cout << "Graph Before Emptying: " << endl;
    graph.printGraph();

    cout << "\nRemoving Edges" << endl;
    for (int i = 0; i < VERTEXES; i++) {
        for (int j = 0; j < VERTEXES; j++) {
            if (graph.isEdge(i, j)) {
                graph.removeEdge(i, j);
                cout << "\nNumber of Vertexes: " << graph.getVertexCount() << endl;
                cout << "Number of Edges: " << graph.getEdgeCount() << endl;
            }
        }
    }

    cout << "\nGraph After Removing Edges" << endl;
    graph.printGraph();

    cout << "\nRemoving Vertices" << endl;
    int vertexCount = graph.getVertexCount();
    for (int i = 0; i < vertexCount; i++) {
        if (graph.isVertex(0)) {
            graph.removeVertex(0);
            cout << "\nNumber of Vertexes: " << graph.getVertexCount() << endl;
            cout << "Number of Edges: " << graph.getEdgeCount() << endl;
        }
    }

    cout << "\nGraph After Emptying: " << endl;
    graph.printGraph();

    cout << "\nTesting Complete" << endl;

    return 0;
}
