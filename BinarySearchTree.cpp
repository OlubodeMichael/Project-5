#include "BinarySearchTree.hpp"
#include <iostream>
using namespace std;

// Create a new node with the given value
Node* BinarySearchTree::createNode(int value) {
    return new Node(value);
}

// Insert a node with the specified value into the binary search tree
Node* BinarySearchTree::insertNode(Node* node, int value) {
    if (node == nullptr) {
        return createNode(value); // Base case: Create a new node when reaching an empty spot
    }
    
    // Recursive insertion based on the comparison of values
    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    }
    
    return node;
}

// Find the node with the minimum value in the binary search tree
Node* BinarySearchTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Remove a node with the specified value from the binary search tree
Node* BinarySearchTree::removeNode(Node* node, int value) {
    if (node == nullptr) {
        return node; // Base case: Value not found, return null
    }
    
    // Recursive removal based on the comparison of values
    if (value < node->data) {
        node->left = removeNode(node->left, value);
    } else if (value > node->data) {
        node->right = removeNode(node->right, value);
    } else {
        // Node to be removed found
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = removeNode(node->right, temp->data);
    }
    
    return node;
}

// Perform in-order traversal of the binary search tree
void BinarySearchTree::inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->data << " "; // Process the current node
        inOrderTraversal(node->right);
    }
}

// Perform pre-order traversal of the binary search tree
void BinarySearchTree::preOrderTraversal(Node* node) {
    if (node != nullptr) {
        cout << node->data << " "; // Process the current node
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
    }
}

// Perform post-order traversal of the binary search tree
void BinarySearchTree::postOrderTraversal(Node* node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " "; // Process the current node
    }
}

// Recursively clear the binary search tree
void BinarySearchTree::clearTree(Node* node) {
    if (node == nullptr) {
        return; // Base case: If the node is null, nothing to clear
    }
    clearTree(node->left); // Recursively clear the left subtree
    clearTree(node->right); // Recursively clear the right subtree
    
    delete node; // Delete the current node
}

// Calculate the height of the binary search tree
int BinarySearchTree::height(Node* node) {
    if (node == nullptr) {
        return -1; // Base case: Height of an empty subtree is -1
    }
    return max(height(node->left), height(node->right)) + 1;
}

// Check if the binary search tree is balanced
bool BinarySearchTree::isBalanced(Node* node) {
    if(node == nullptr) {
        return true; // An empty subtree is always balanced
    }
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    // Check if the heights of the left and right subtrees differ by at most 1
    return (abs(leftHeight - rightHeight) <= 1) && isBalanced(node->left) && isBalanced(node->right);
}

// End of the BinarySearchTree class implementation
