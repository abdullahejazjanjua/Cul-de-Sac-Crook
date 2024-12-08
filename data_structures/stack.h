#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;
};

template <typename T>
class Stack {
    Node<T>* head;

public:
    Stack() {
        head = nullptr;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>;
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node<T>* cur = head;
        head = head->next;
        delete cur;
    }

    void display() {
        Node<T>* cur = head;
        cout << endl;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

#endif
