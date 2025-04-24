//Lauren White - Lab 7

#include "Node.h"

//Overloaded << operator for printing
ostream& operator<<(ostream& os, const Node& node)
{
    //Output the word and its number
    os << node.number << ": " << node.count;
    return os;
}