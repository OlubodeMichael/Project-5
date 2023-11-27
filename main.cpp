/**
 Name: Michael Olubode
 Date: Novermber 24, 2023
 Class: CSDP 250 Fall 2023
 purpose: This code defines the implementation of a binary search tree (BST) in C++. A binary search tree is a binary tree data structure
        where each node has at most two child nodes, typically named "left" and "right". The key property of a binary search tree is that
        the left child of a node contains values smaller than the node's value, and the right child contains values greater than the node's value.
        This ordering property allows for efficient search, insertion, and deletion of elements.
**/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinarySearchTree.hpp"
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time_t(0));

    // Generate a random size for the Binary Search Tree between 35 and 100 nodes
    int size = rand() % (100 - 35 + 1) + 35;

    // Create an instance of the BinarySearchTree
    BinarySearchTree bst;

    // Seed the random number generator with the current time again
    srand(static_cast<unsigned>(time(nullptr)));

    // Create and insert 'size' random natural numbers (less than 100) into the BST
    for (int i = 0; i < size; ++i) {
        int value = rand() % 100; // Generate a random number less than 100
        bst.insert(value);
    }

    // Display the in-order traversal of the BST
    cout << "In-order traversal: ";
    bst.inOrderTraversal();
    
    // Prompt the user to enter a number to be removed from the BST
    int remove;
    cout << "Enter a number you want to remove from the binary search tree: ";
    cin >> remove;
    
    // Remove the entered number from the BST
    bst.remove(remove);
    
    // Display the post-order traversal of the BST after removal
    cout << "Post-order traversal after removal: ";
    bst.postOrderTraversal();
    
    // Check if the BST is an AVL tree and display the result
    if (bst.isAVL()) {
        cout << "The BST is an AVL tree" << endl;
    } else {
        cout << "The binary search tree is not an AVL tree" << endl;
    }

    return 0;
}
