#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
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
    unordered_map<string, Node_graph<T>*> list; // Keyed by a unique string identifier (e.g., name)

public:
    Graph() {}

    void addEdge(const string& uKey, T uVal, const string& vKey, T vVal) {
        // Add edge from u to v
        Node_graph<T>* newNode = new Node_graph<T>(vVal);
        newNode->next = list[uKey];
        list[uKey] = newNode;

        // Add edge from v to u (undirected graph)
        newNode = new Node_graph<T>(uVal);
        newNode->next = list[vKey];
        list[vKey] = newNode;
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

    void BFS(const string& startKey) {
        unordered_map<string, bool> visited;
        queue<string> q;

        visited[startKey] = true;
        q.push(startKey);

        cout << "BFS starting from vertex " << startKey << ": ";

        while (!q.empty()) {
            string currentKey = q.front();
            q.pop();
            cout << currentKey << " ";

            Node_graph<T>* temp = list[currentKey];
            while (temp) {
                string adjKey = temp->val.getName(); // Assuming T has a `getName` function
                if (!visited[adjKey]) {
                    visited[adjKey] = true;
                    q.push(adjKey);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void DFS(const string& startKey) {
        unordered_map<string, bool> visited;
        DFSHelper(startKey, visited);
        cout << endl;
    }

    void DFSHelper(const string& key, unordered_map<string, bool>& visited) {
        visited[key] = true;
        cout << key << " ";

        Node_graph<T>* temp = list[key];
        while (temp) {
            string adjKey = temp->val.getName(); // Assuming T has a `getName` function
            if (!visited[adjKey]) {
                DFSHelper(adjKey, visited);
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

