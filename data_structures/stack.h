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

    bool isEmpty()
    {
        return head == nullptr;
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

    cout << "\n======================================" << endl;
    cout << "         Player's Robbery Levels      " << endl;
    cout << "======================================" << endl;

    if (cur == nullptr) 
    {
        cout << "No robberies recorded yet!" << endl;
    } 
    else 
    {
        cout << "Robbery Levels: ";
        while (cur != nullptr) 
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    cout << "======================================" << endl;
}


    int size() 
    {
        int count = 0;
        Node_stack<T>* cur = head;
        while (cur != nullptr) 
        {
            count++;
            cur = cur->next;
        }
        return count;
    }

    void sortedInsert(T val)
    {
        if (head == nullptr || head->val <= val) 
        {
            push(val);
        } 
        else 
        {
            T temp = head->val;
            pop();
            sortedInsert(val);
            push(temp);
        }
    }

    void sortStack()
    {
        if (head == nullptr) 
        {
            return;
        }

        T top = head->val;
        pop();
        sortStack();
        sortedInsert(top);
    }
};

#endif