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

    //Word node data and pointers
    int number;
    int count;
    Node* left;
    Node* right;

    //Constructor
    Node(int num) : number(num), count(1), left(nullptr), right(nullptr) {};

    //Get the number
    int getNumber() const { return number; }

    //Get the count
    int getCount() const { return count; }

    //Set the number
    void setNumber(const int& num) { number = num; }

    //Set the count
    void setCount(int c) { count = c; }

    //Increment the count
    void increment() { count++; }

    //Overloaded << operator for printing
    friend ostream& operator<<(ostream& os, const Node& node);

    //Destructor
    ~Node() {}
};

#endif