/*********************
Name: Julian Cotto
Final Project - Graphs
Purpose: source file for graph.h
**********************/

#include "graph.h"


Graph::Graph() {}

Graph::~Graph() {}

bool Graph::addEdge(int src, int dest, Data& data) {
    bool result = true;
    if (src >= adjList.size() || dest >= adjList.size()) {
        result = false;
    } else {
        adjList[src].push_back({dest, data});
    }
    return result;
}

bool Graph::removeEdge(int src, int dest) {
    bool result = false;
    if (src < adjList.size()) {
        auto& edges = adjList[src];
        auto it = edges.begin();
        while (it != edges.end()) {
            if (it->first == dest) {
                it = edges.erase(it);
                result = true;
            } else {
                ++it;
            }
        }
    }
    return result;
}

bool Graph::addVertex(int vertex) {
    bool result = true;
    if (vertex < 0) {
        result = false;
    } else if (vertex >= adjList.size()) {
        adjList.resize(vertex + 1);
    }
    return result;
}

bool Graph::removeVertex(int vertex) {
    bool result = true;
    if (vertex < 0 || vertex >= adjList.size()) {
        result = false;
    } else {
        adjList[vertex].clear();
        for (int i = 0; i < adjList.size(); i++) {
            removeEdge(i, vertex);
        }
        adjList.erase(adjList.begin() + vertex);
    }
    return result;
}


Data Graph::getEdgeData(int src, int dest) {
    const auto& edges = adjList[src];
    for (auto& edge : edges) {
        if (edge.first == dest) {
            return edge.second;
        }
    }
    throw runtime_error("Edge not found");
}


void Graph::printGraph() {
    if (adjList.empty()) {
        cout << "Graph is empty" << endl;
    } else {
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Vertex " << i << ":";
            for (auto& edge : adjList[i]) {
                cout << " -> " << edge.first << " (" << edge.second.id << ", " << edge.second.data << ")";
            }
            cout << endl;
        }
    }
}

void Graph::printAllEdgeData() {
    for (int i = 0; i < adjList.size(); i++) {
        for (auto& edge : adjList[i]) {
            cout << "Edge (" << i << ", " << edge.first << "): id = " << edge.second.id << ", data = " << edge.second.data << endl;
        }
    }
}

int Graph::getVertexCount() {
    return adjList.size();
}

int Graph::getEdgeCount() {
    int count = 0;
    for (auto& edges : adjList) {
        count += edges.size();
    }
    return count;
}

Graph Graph::getBFST(int source)
{
    Graph bfst;
    vector<bool> visited(adjList.size(), false);
    queue<int> queue;

    visited[source] = true;
    queue.push(source);
    bfst.addVertex(source);

    while (!queue.empty())
    {
        int vertex = queue.front();
        queue.pop();

        for (auto& edge : adjList[vertex])
        {
            int dest = edge.first;
            if (!visited[dest])
            {
                visited[dest] = true;
                queue.push(dest);
                bfst.addVertex(dest);
                bfst.addEdge(vertex, dest, edge.second);
            }
        }
    }

    return bfst;
}


void Graph::clearGraph() {
    adjList.clear();
}

void Graph::dfsUtil(int v, vector<bool> &visited, Graph &dfst)
{
    visited[v] = true;
    for (auto& edge : adjList[v])
    {
        int dest = edge.first;
        if (!visited[dest])
        {
            dfst.addEdge(v, dest, edge.second);
            dfsUtil(dest, visited, dfst);
        }
    }
}

Graph Graph::getDFST(int source)
{
    Graph dfst;
    vector<bool> visited(adjList.size(), false);
    dfst.addVertex(source);
    dfsUtil(source, visited, dfst);
    return dfst;
}




void Graph::depthFirstTraversal(int source) {
    vector<bool> visited(adjList.size(), false);
    stack<int> stack;

    stack.push(source);

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            visited[vertex] = true;
            cout << vertex << " ";

            for (const auto& edge : adjList[vertex]) {
                int dest = edge.first;
                if (!visited[dest]) {
                    stack.push(dest);
                }
            }
        }
    }
}

void Graph::breadthFirstTraversal(int source) {
    vector<bool> visited(adjList.size(), false);
    queue<int> queue;

    visited[source] = true;
    queue.push(source);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        cout << vertex << " ";

        for (auto& edge : adjList[vertex]) {
            int dest = edge.first;
            if (!visited[dest]) {
                visited[dest] = true;
                queue.push(dest);
            }
        }
    }
}

bool Graph::isVertex(int vertex) {
    return (vertex >= 0 && vertex < adjList.size());
}


bool Graph::isEdge(int src, int dest) {
    bool result = false;
    if (!(src < 0 || src >= adjList.size())) {
        for (auto& edge : adjList[src]) {
            if (edge.first == dest) {
                result = true;
            }
        }
    }
    return result;
}
