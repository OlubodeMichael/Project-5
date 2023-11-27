#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include <iostream>
using namespace std;

// Definition of a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

    // Private helper functions for internal operations
    Node* createNode(int value);
    Node* insertNode(Node* node, int value);
    Node* findMin(Node* node);
    Node* removeNode(Node* node, int value);
    void inOrderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);
    void clearTree(Node* node);
    int height(Node* node);
    bool isBalanced(Node* node);

public:
    // Constructor: Initializes an empty binary search tree
    BinarySearchTree() : root(nullptr) {}

    // Destructor: Clears the entire binary search tree
    ~BinarySearchTree() {
        clear();
    }

    // Public function to insert a value into the binary search tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Public function to remove a value from the binary search tree
    void remove(int value) {
        root = removeNode(root, value);
    }

    // Public function to perform in-order traversal of the binary search tree
    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }

    // Public function to perform pre-order traversal of the binary search tree
    void preOrderTraversal() {
        preOrderTraversal(root);
        cout << endl;
    }

    // Public function to perform post-order traversal of the binary search tree
    void postOrderTraversal() {
        postOrderTraversal(root);
        cout << endl;
    }

    // Public function to check if the binary search tree is an AVL tree
    bool isAVL() {
        return isBalanced(root);
    }

    // Public function to clear the entire binary search tree
    void clear() {
        clearTree(root);
        root = nullptr;
    }

};
#endif /* BinarySearchTree_hpp */
