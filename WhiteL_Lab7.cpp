/*********************************************************************************************************************\
Lauren White - Lab 7
 Binary Tree to AVL Tree Converter
 **

\*********************************************************************************************************************/
//Header written by Copilot

#include "BinaryTree.h"

using namespace std;

int choice;
//BinaryTree tree;


int main()
{
    BinaryTree tree;
    //AVLTree treeCopy;
    int choice = 0;

    //Loop until the user chooses to exit
    while (choice != 2)
    {
        // Display the menu
        cout << "Menu:\n";
        cout << "1) Insert an Integer\n";
        cout << "2) Balance Tree\n";
        cout << "3) Quick Balance\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        //If the user chooses to enter a number
        if (choice == 1)
        {
            int number;
            cout << "Enter Integer: ";
            cin >> number;

            //Insert the number into the tree
            tree.insert(number);

            //Pre-order print the tree with the new number
            //############################################################################################
        }

        //If the user chooses to slow balance
        else if (choice == 2)
        {
            cout << "Exiting...\n";

            //Use balance function************************************************************************
            //Pre-order

        }        
        
        //If the user chooses to quick balance
        else if (choice == 3)
        {
            cout << "Exiting...\n";

            //Use quick balance function******************************************************************
            //Pre-order

        }        
        
        //If the user chooses to exit
        else if (choice == 4)
        {
            cout << "Exiting...\n";

            return 0;
        }

        //Otherwise, ask the user to try again
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}