Lab 7 - BST -> AVL Tree
You will insert values into a binary search tree that is not self-balancing, like the AVL tree.
After every insert operation, print the pre-order traversal of the binary search tree.

For making the binary search tree balanced, the basic method would be to implement the following algorithm:

Initialize an empty AVL tree. Iteratively delete the root of the binary search tree and insert it in the AVL tree until the binary search tree becomes empty. 
Use a pre-order traversal, combined with the traditional insert method of an AVL tree as demonstrated in class. 


Unfortunately, this approach is slow, performing in O(n log n) time to make a binary search tree with n nodes balanced [for a tree with n = 1000, this is ~10000 steps.

Now, design an O(n) time algorithm for making a binary search tree balanced. 
Hint: use divide-and-conquer technique You will need to use an array, a vector, or a linked list. 
My preference is to use a vector, however, this can be done by converting the tree into a linked list by associating the pointers in the correct order (in our case, pre-order) 
and then using divide and conquer on the list.


Assume all keys are all unique.

For this assignment, you must load the data into a Binary Search Tree according to the rules of the BST.