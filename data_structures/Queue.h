#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
    }

    void dequeue() {
        if (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (!front) {
                rear = nullptr;
            }
        }
    }

    T peek() const {
        if (front) {
            return front->data;
        }
        throw std::runtime_error("Queue is empty");
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
