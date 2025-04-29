// Lauren White - Lab 7

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "Node.h"

using namespace std;

class AVLTree 
{
private:
    Node* root;

    //Get the height of the given node
    int getHeight(Node* node) { return node ? node->height : 0; }

    //Calculate the balance factor of the given node
    int getBalance(Node* node) { return node ? getHeight(node->left) - getHeight(node->right) : 0;}

    //Perform a right rotation on the given node
    Node* rightRotate(Node* y);

    //Perform a left rotation on the given node
    Node* leftRotate(Node* x);

    //Find the node with the smallest value
    Node* minValueNode(Node* node);

    //Insert a key into the AVL tree
    Node* insert(Node* node, int key);

    //Delete a key from the AVL tree
    Node* deleteNode(Node* root, int key);

    //Display the tree using pre-order
    void preorder(Node* node);

public:

    //Default constructor
    AVLTree() : root(nullptr) {}

    //Insert a key into the tree
    void insert(int key) { root = insert(root, key); }

    //Delete a key from the tree
    void deleteValue(int key) { root = deleteNode(root, key); }

    //Display the tree using pre-order
    void displayPreorder();
};

#endif