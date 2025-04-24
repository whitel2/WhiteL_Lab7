// Lauren White - Lab 7

#include "BinaryTree.h"


/////////////////////////////////////////////////////////////////////////////////CHANGE TO INORDER!!!!!!!


//Helper function to insert a number into a tree
void BinaryTree::insertHelper(Node*& node, const int& number)
{
    //If there is no node for this number, create a new one
    if (!node)
    {
        node = new Node(number);
    }

    //Create a number node to the left
    else if (number < node->number)
    {
        insertHelper(node->left, number);
    }

    //Create a number node to the right
    else if (number > node->number)
    {
        insertHelper(node->right, number);
    }

    //If the number node already exists, increment the count
    else
    {
        node->increment();
    }
}

//Helper function to delete a number from a tree
Node* BinaryTree::deleteHelper(Node* node, const int& number)
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function and return nullptr
        return nullptr;
    }

    //Delete a number node to the left
    if (number < node->number)
    {
        node->left = deleteHelper(node->left, number);
    }

    //Delete a number node to the left
    else if (number > node->number)
    {
        node->right = deleteHelper(node->right, number);
    }

    //If the number is found
    else
    {
        //If the node is a leaf
        if (!node->left && !node->right)
        {
            //Delete the node and return null
            delete node;
            return nullptr;
        }

        //If there is one child
        else if (!node->left || !node->right)
        {
            //Delete the child
            Node* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }

        //If there are two children
        else
        {

            Node* child = node->right;

            //Find the next child (inorder)
            while (child->left)
            {
                child = child->left;
            }

            //Copy the child's data
            //node->number = child->number;
           // node->count = child->count;

            //Delete the child
            node->right = deleteHelper(node->right, child->number);
        }
    }
    return node;
}

//Helper function for in-order traversal to write tree to a file
void BinaryTree::inorderHelper(Node* node, ofstream& outFile) const
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function
        return;
    }

    //Traverse the left subtree (inorder)
    inorderHelper(node->left, outFile);

    //Print the current node's number and count to the output file
    outFile << node->number << ": " << node->count << endl;

    //Traverse the right subtree (inorder)
    inorderHelper(node->right, outFile);
}

//Method to search for a number in a binary tree
bool BinaryTree::searchHelper(Node* node, const int& number) const
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function
        return false;
    }

    //If the current node's number matches the target number
    if (number == node->number)
    {
        //Return true
        return true;
    }

    //Search the left subtree
    else if (number < node->number)
    {
        return searchHelper(node->left, number);
    }

    //Search the right subtree
    else return searchHelper(node->right, number);
}

//Helper function to destroy a tree
void BinaryTree::destroyTree(Node* node)
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function
        return;
    }

    //Destroy all the right and left subtrees
    destroyTree(node->left);
    destroyTree(node->right);

    //Destroy the given number node
    delete node;
}