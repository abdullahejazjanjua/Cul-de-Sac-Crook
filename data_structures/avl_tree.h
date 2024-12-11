#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm> 

using namespace std;

template <typename T>
struct Node_tree 
{
    T val;
    Node_tree* left;
    Node_tree* right;
    int height;

    Node_tree(T value) {
        val = value;
        left = right = nullptr;
        height = 1;
    }
};

template <typename T>
class AVL 
{
private:
    Node_tree<T>* root;

    int getHeight(Node_tree<T>* node) 
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node_tree<T>* node) 
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node_tree<T>* leftRotate(Node_tree<T>* x) 
    {
        Node_tree<T>* y = x->right;
        Node_tree<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return y;
    }

    Node_tree<T>* rightRotate(Node_tree<T>* y) 
    {
        Node_tree<T>* x = y->left;
        Node_tree<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node_tree<T>* add(Node_tree<T>* node, T val) 
    {
        if (!node) return new Node_tree<T>(val);

        if (val < node->val) 
        {
            node->left = add(node->left, val);
        } 
        else if (val > node->val) 
        {
            node->right = add(node->right, val);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1 && val < node->left->val) 
        {
            return rightRotate(node);
        }
        if (balance > 1 && val > node->left->val) 
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && val > node->right->val) 
        {
            return leftRotate(node);
        }
        if (balance < -1 && val < node->right->val) 
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node_tree<T>* node) 
    {
        if (!node) return;
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node_tree<T>* node) 
    {
        if (!node) return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    void postOrder(Node_tree<T>* node) 
    {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }

    Node_tree<T>* deleteNode(Node_tree<T>* node, T val) 
    {
        if (!node) return node;

        if (val < node->val) 
        {
            node->left = deleteNode(node->left, val);
        } 
        else if (val > node->val) 
        {
            node->right = deleteNode(node->right, val);
        } 
        else 
        {
            if (!node->left || !node->right) 
            {
                Node_tree<T>* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }

            Node_tree<T>* temp = inOrderPredecessor(node);
            node->val = temp->val;
            node->left = deleteNode(node->left, temp->val);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);

        if (balance > 1 && val < node->left->val) 
        {
            return rightRotate(node);
        }
        if (balance > 1 && val > node->left->val) 
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && val > node->right->val) 
        {
            return leftRotate(node);
        }
        if (balance < -1 && val < node->right->val) 
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node_tree<T>* inOrderPredecessor(Node_tree<T>* node) 
    {
        node = node->left;
        while (node->right) {
            node = node->right;
        }
        return node;
    }

public:
    AVL() : root(nullptr) {}

    void insert(T val) 
    {
        root = add(root, val);
    }

    void traverseTree(int key) 
    {
        switch (key) {
        case 0:
            preOrder(root);
            break;
        case 1:
            postOrder(root);
            break;
        case 2:
            inOrder(root);
            break;
        default:
            break;
        }
    }

    void deletion(T val) 
    {
        root = deleteNode(root, val);
    }
};

#endif 
