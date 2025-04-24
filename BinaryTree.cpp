// Lauren White - Lab 7

#include "BinaryTree.h"
/*
//Helper function to insert a word into a tree
void BinaryTree::insertHelper(WordNode*& node, const string& word)
{
    //If there is no node for this word, create a new one
    if (!node)
    {
        node = new WordNode(word);
    }

    //Create a word node to the left
    else if (word < node->word)
    {
        insertHelper(node->left, word);
    }

    //Create a word node to the right
    else if (word > node->word)
    {
        insertHelper(node->right, word);
    }

    //If the word node already exists, increment the count
    else
    {
        node->increment();
    }
}

//Method to insert a word into a binary tree
void BinaryTree::insert(string word)
{
    string processedWord = processWord(word);

    //If there is a processed word
    if (!processedWord.empty())
    {
        //Insert the word
        insertHelper(root, processedWord);
    }
}

//Helper function to delete a word from a tree
WordNode* BinaryTree::deleteHelper(WordNode* node, const string& word)
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function and return nullptr
        return nullptr;
    }

    //Delete a word node to the left
    if (word < node->word)
    {
        node->left = deleteHelper(node->left, word);
    }

    //Delete a word node to the left
    else if (word > node->word)
    {
        node->right = deleteHelper(node->right, word);
    }

    //If the word is found
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
            WordNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }

        //If there are two children
        else
        {

            WordNode* child = node->right;

            //Find the next child (inorder)
            while (child->left)
            {
                child = child->left;
            }

            //Copy the child's data
            //node->word = child->word;
           // node->count = child->count;

            //Delete the child
            node->right = deleteHelper(node->right, child->word);
        }
    }
    return node;
}

//Helper function for in-order traversal to write tree to a file
void BinaryTree::inorderHelper(WordNode* node, ofstream& outFile) const
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function
        return;
    }

    //Traverse the left subtree (inorder)
    inorderHelper(node->left, outFile);

    //Print the current node's word and count to the output file
    outFile << node->word << ": " << node->count << endl;

    //Traverse the right subtree (inorder)
    inorderHelper(node->right, outFile);
}

//Method to search for a word in a binary tree
bool BinaryTree::searchHelper(WordNode* node, const string& word) const
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function
        return false;
    }

    //If the current node's word matches the target word
    if (word == node->word)
    {
        //Return true
        return true;
    }

    //Search the left subtree
    else if (word < node->word)
    {
        return searchHelper(node->left, word);
    }

    //Search the right subtree
    else return searchHelper(node->right, word);
}

//Helper function to destroy a tree
void BinaryTree::destroyTree(WordNode* node)
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

    //Destroy the given word node
    delete node;
}
*/