#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node_queue {
    T val;
    Node_queue* next;
};

template <typename T>
class Queue {
private:
    Node_queue<T>* front;
    Node_queue<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const T& value) {
        Node_queue<T>* newNode = new Node_queue<T>{value, nullptr};
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
    }

    T dequeue() {
        if (front) {
            Node_queue<T>* temp = front;
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

    void display()
    {
        Node_queue<T> *cur = front;
        while(cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif
