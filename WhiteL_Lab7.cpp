/*********************************************************************************************************************\
 * Lauren White - Lab 7
 * Binary Tree to AVL Tree Converter
 *
 * Description:
 * This program allows the user to create and interact with a Binary Search Tree (BST). It provides the following
 * functionalities:
 *   1. Insert integers into the BST while maintaining the BST properties.
 *   2. Balance the tree using a slow AVL-based method by converting the BST to an AVL Tree.
 *   3. Balance the tree using a faster divide-and-conquer technique (O(n) time complexity).
 *   4. Display the pre-order traversal of the tree after each operation to visualize its structure.
 *
 * Menu Options:
 *   1) Insert an Integer:
 *      - Prompts the user to enter an integer.
 *      - Inserts the integer into the BST.
 *      - Displays the pre-order traversal of the updated tree.
 *
 *   2) Balance Tree (Slow Method - AVL):
 *      - Converts the BST into a balanced AVL Tree using a sorted vector and traditional AVL insertion.
 *      - Displays the pre-order traversal of the balanced AVL Tree.
 *
 *   3) Quick Balance Tree (Fast Method):
 *      - Balances the BST directly in O(n) time using a divide-and-conquer technique.
 *      - Displays the pre-order traversal of the fast-balanced tree.
 *
 *   4) Exit:
 *      - Terminates the program.
 *
 * Usage:
 * The user can interact with the program by selecting options from the menu. After each operation, the program
 * outputs the pre-order traversal of the tree to visualize the changes.
\*********************************************************************************************************************/
//Header written by Copilot

#include "BinaryTree.h"
#include "AVLTree.h"

using namespace std;

int main()
{
    BinaryTree tree;
    AVLTree AVLTree;
    int choice = 0;

    //Loop until the user chooses to exit
    while (choice != 4)
    {
        // Display the menu
        cout << "Menu:\n";
        cout << "1) Insert a number:\n";
        cout << "2) Balance Tree\n";
        cout << "3) Quick Balance Tree\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        //If the user chooses to insert a number
        if (choice == 1)
        {
            int number;
            cout << "Key to be inserted: ";
            cin >> number;

            //Insert the number into the binary tree
            tree.insert(number);

            //Traverse the tree using pre-order
            cout << "Pre-order traversal: ";
            tree.preorderTraversal();
        }

        //If the user chooses to balance the tree using the AVL-based method
        else if (choice == 2)
        {
            vector<int> sortedArray;

            // Flatten the BinaryTree into a sorted vector (in-order)
            tree.flattenTree(tree.getRoot(), sortedArray);

            // Insert all elements into a new AVL tree
            for (int num : sortedArray)
            {
                AVLTree.insert(num);
            }

            //Traverse the tree using pre-order
            cout << "Pre-order traversal of tree after balancing with AVL tree based method: ";
            AVLTree.displayPreorder();
        }

        // f the user chooses to balance the tree using the quick method
        else if (choice == 3)
        {
            vector<int> sortedArray;

            tree.fastBalance();

            //Traverse the tree using pre-order
            cout << "Pre-order traversal of tree after balancing with faster method: ";
            tree.preorderTraversal();
        }

        //If the user chooses to exit, exit
        else if (choice == 4)
        {
            cout << "Exiting...\n";
        }

        //If the user enters an invalid option, retry
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
