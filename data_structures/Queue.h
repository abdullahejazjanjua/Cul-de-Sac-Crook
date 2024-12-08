#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;
};

template <typename T>
class Queue {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>{value, nullptr};
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
    }

    T dequeue() {
        if (front) {
            Node<T>* temp = front;
            T value = front->val;
            front = front->next;
            delete temp;
            if (!front) {
                rear = nullptr;
            }
            return value;
        }
        throw runtime_error("Queue is empty");
    }

    T peek() const {
        if (front) {
            return front->val; 
        }
        throw runtime_error("Queue is empty");
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif


