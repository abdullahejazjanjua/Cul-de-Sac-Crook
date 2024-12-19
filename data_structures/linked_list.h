#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

// Define the node_list structure outside the class, with the template parameter
template <typename T>
struct node_list
{
    T val;
    node_list *next;
    
    // Constructor to initialize the value and next pointer
    node_list(T value) : val(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
    node_list<T> *head;

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }

    // Destructor
    ~LinkedList()
    {
        node_list<T> *tmp = head;
        while (head != nullptr)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Add at head
    void AddAtHead(T val)
    {
        node_list<T> *newNode = new node_list<T>(val);
        newNode->next = head;
        head = newNode;
    }

    // Add at tail
    void AddAtTail(T val)
    {
        node_list<T> *newNode = new node_list<T>(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        node_list<T> *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    // Delete node with given value
    void DeleteNode(T key)
    {
        node_list<T> *cur = head, *prev = nullptr;

        if (head == nullptr)
        {
            cout << "\nThe Linked List is empty\n";
            return;
        }

        // If the key is in the head node
        if (cur != nullptr && cur->val == key)
        {
            head = cur->next;  // Move head to next node
            delete cur;
            return;
        }

        // Search for the key to delete
        while (cur != nullptr && cur->val != key)
        {
            prev = cur;
            cur = cur->next;
        }

        // If key was not found
        if (cur == nullptr)
        {
            cout << "\nKey not found in the list\n";
            return;
        }

        // Unlink the node
        prev->next = cur->next;
        delete cur;
    }

    // Display the list
    void display() const
    {
        node_list<T> *cur = head;
        cout << endl;
        while (cur != nullptr)
        {
            cur->val.print();
            cout << endl;
            cur = cur->next;
        }
        cout << endl;
    }
};

#endif // LINKED_LIST_H
