// Lauren White - Lab 7

#include "AVLTree.h"

//Perform a right rotation on the given node
Node* AVLTree::rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    //Perform the rotation
    x->right = y;
    y->left = T2;

    //Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    //Return the new root
    return x;
}

//Perform a left rotation on the given node
Node* AVLTree::leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    //Perform the rotation
    y->left = x;
    x->right = T2;

    //Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    //Return the new root
    return y;
}

//Find the node with the smallest value
Node* AVLTree::minValueNode(Node* node)
{
    Node* current = node;

    //Traverse to the leftmost leaf
    while (current->left)
    {
        current = current->left;
    }

    return current;
}

//Insert a key into the AVL tree
Node* AVLTree::insert(Node* node, int key)
{
    //If there is no data at this node, create a new node with the given key
    if (!node)
    {
        return new Node(key);
    }

    //If the key to be inserted is less than the current node's data
    if (key < node->number)
    {
        //Insert the key in the left subtree
        node->left = insert(node->left, key);
    }

    //If the key to be inserted is greater than the current node's data
    else if (key > node->number)
    {
        //Insert the key in the right subtree
        node->right = insert(node->right, key);
    }

    //If the key already exists, return the current node
    else
    {
        return node;
    }

    // Update height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    //Left Left Rotation
    if (balance > 1 && key < node->left->number)
    {
        return rightRotate(node);
    }

    //Right Right Rotation
    if (balance < -1 && key > node->right->number)
    {
        return leftRotate(node);
    }
    
    //Left Right Rotation
    if (balance > 1 && key > node->left->number)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //Right Left Rotation
    if (balance < -1 && key < node->right->number)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

//Delete a key from the AVL tree
Node* AVLTree::deleteNode(Node* root, int key)
{
    //If there is no data, exit
    if (!root)
    {
        return root;
    }

    //If the key to be deleted is smaller than the current node's data
    if (key < root->number)
    {
        //Search the left subtree
        root->left = deleteNode(root->left, key);
    }

    //If the key to be deleted is greater than the current node's data
    else if (key > root->number)
    {
        //Search the right subtree
        root->right = deleteNode(root->right, key);
    }

    else
    {
        //Node with one or no children
        if (!root->left || !root->right)
        {
            // Check if the node has only one child or no children
            Node* temp = root->left ? root->left : root->right;

            //If there are no children
            if (!temp)
            {
                //Remove the current node
                temp = root;
                root = nullptr;
            }

            //If there is one child
            else
            {
                //Replace the current node with the child
                *root = *temp;
            }

            // Delete the current node (now stored in temp)
            delete temp;
        }

        else
        {
            // Node with two children: Get the in-order successor
            Node* temp = minValueNode(root->right);
            root->number = temp->number;

            // Delete the in-order successor
            root->right = deleteNode(root->right, temp->number);
        }
    }

    //If there is no data to process, exit
    if (!root)
    {
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    //Left Left Rotation
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    //Left Right Rotation
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //Right Right Rotation
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    //Right Left Rotation
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//Pre-order traversal of the tree
void AVLTree::preorder(Node* node)
{
    //If there is no data, exit the function
    if (!node)
    {
        return;
    }

    // Print the current node's data
    cout << node->number << " ";

    // Traverse the left subtree
    preorder(node->left);

    // Traverse the right subtree
    preorder(node->right);
}

//Display the tree using pre-order
void AVLTree::displayPreorder()
{
    preorder(root);
    cout << endl;
}