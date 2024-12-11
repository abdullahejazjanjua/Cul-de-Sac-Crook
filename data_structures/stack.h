#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Node_stack 
{
    T val;
    Node_stack* next;
};

template <typename T>
class Stack 
{
    Node_stack<T>* head;

public:
    Stack() 
    {
        head = nullptr;
    }

    void push(T val) 
    {
        Node_stack<T>* newNode = new Node_stack<T>;
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }

    void pop() 
    {
        if (head == nullptr) 
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node_stack<T>* cur = head;
        head = head->next;
        delete cur;
    }

    void display() 
    {
        Node_stack<T>* cur = head;
        cout << endl;
        while (cur != nullptr) 
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

#endif
