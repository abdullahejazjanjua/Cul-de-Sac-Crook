#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include "Queue.h"
using namespace std;

template <typename T>
struct Node_graph {
    T val;
    Node_graph* next;
    Node_graph(T value) : val(value), next(nullptr) {}
};

template <typename T>
class Graph {
private:
    unordered_map<T, Node_graph<T>*> list;

public:
    Graph() {}

    void addEdge(T u, T v) {
        Node_graph<T>* newNode = new Node_graph<T>(v);
        newNode->next = list[u];
        list[u] = newNode;

        newNode = new Node_graph<T>(u);
        newNode->next = list[v];
        list[v] = newNode;
    }

    void printGraph() const {
        for (const auto& pair : list) {
            cout << "Vertex " << pair.first << ": ";
            Node_graph<T>* temp = pair.second;
            while (temp) {
                cout << temp->val << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void BFS(T start) {
        unordered_map<T, bool> visited;
        Queue<T> q;

        visited[start] = true;
        q.enqueue(start);

        cout << "BFS starting from vertex " << start << ": ";

        while (!q.isEmpty()) {
            T vertex = q.dequeue();
            cout << vertex << " ";

            Node_graph<T>* temp = list[vertex];
            while (temp) {
                T adjVertex = temp->val;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.enqueue(adjVertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void DFS(T start) {
        unordered_map<T, bool> visited;
        DFSHelper(start, visited);
        cout << endl;
    }

    void DFSHelper(T vertex, unordered_map<T, bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        Node_graph<T>* temp = list[vertex];
        while (temp) {
            T adjVertex = temp->val;
            if (!visited[adjVertex]) {
                DFSHelper(adjVertex, visited);
            }
            temp = temp->next;
        }
    }

    ~Graph() {
        for (auto& pair : list) {
            Node_graph<T>* temp = pair.second;
            while (temp) {
                Node_graph<T>* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }
};

#endif
