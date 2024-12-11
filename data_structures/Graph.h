#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "Queue.h"
using namespace std;

struct Node_graph {
    int val;
    Node_graph* next;
    Node_graph(int value) : val(value), next(nullptr) {}
};

class Graph {
private:

    Node_graph** adjacencyList;
    int size;

public:
    Graph(int vertices) {
        size = vertices;
        adjacencyList = new Node_graph*[size];
        for (int i = 0; i < size; ++i) {
            adjacencyList[i] = nullptr;
        }
    }

    void addEdge(int u, int v) {
        Node_graph* newNode = new Node_graph(v);
        newNode->next = adjacencyList[u];
        adjacencyList[u] = newNode;

        newNode = new Node_graph(u);
        newNode->next = adjacencyList[v];
        adjacencyList[v] = newNode;
    }

    void printGraph() const {
        for (int i = 0; i < size; ++i) {
            cout << "Vertex " << i << ": ";
            Node_graph* temp = adjacencyList[i];
            while (temp) {
                cout << temp->val << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void BFS(int start) {
        bool* visited = new bool[size]();
        Queue<int> q;

        visited[start] = true;
        q.enqueue(start);

        cout << "BFS starting from vertex " << start << ": ";

        while (!q.isEmpty()) {
            int vertex = q.dequeue();
            cout << vertex << " ";


            Node_graph* temp = adjacencyList[vertex];
            while (temp) {
                int adjVertex = temp->val;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.enqueue(adjVertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
        delete[] visited;
    }

    void DFS(int start) {
        bool* visited = new bool[size]();
        DFSHelper(start, visited);
        cout << endl;
        delete[] visited;
    }

    void DFSHelper(int vertex, bool* visited) {
        visited[vertex] = true;
        cout << vertex << " ";


        Node_graph* temp = adjacencyList[vertex];
        while (temp) {
            int adjVertex = temp->val;
            if (!visited[adjVertex]) {
                DFSHelper(adjVertex, visited);
            }
            temp = temp->next;
        }
    }

    ~Graph() {

        for (int i = 0; i < size; ++i) {
            Node_graph* temp = adjacencyList[i];
            while (temp) {
                Node_graph* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adjacencyList;
    }
};

#endif

