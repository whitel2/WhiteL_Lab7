//Lauren White - Lab 7

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node
{
public:

    //Number node data and pointers
    int count;
    int number;
    Node* left;
    Node* right;
    int height;

    //Constructor
    Node(int val) : count(0), number(val), left(nullptr), right(nullptr), height(1) {}

    //Get the number
    int getNumber() const { return number; }

    //Set the number
    void setNumber(const int& num) { number = num; }

    //Increment the count
    void increment() { count++; }

    //Overloaded << operator for printing
    friend ostream& operator<<(ostream& os, const Node& node);

    //Destructor
    ~Node() {}
};

#endif