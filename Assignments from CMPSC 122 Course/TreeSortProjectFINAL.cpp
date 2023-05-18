// Zach Mello
// 4/5/22
// Program recursively alphabetize a set of strings in a user-specified file using the tree sort algorithm while maintaining a balanced binary tree at all times

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Node
{
    string value; // String data
    struct Node* left = NULL; // Pointer to left child
    struct Node* right = NULL; // Pointer to right child
};

struct Node* getEntry(string);
int height(Node*);
int difference(Node*);
Node* rrRotate(Node*);
Node* llRotate(Node*);
Node* lrRotate(Node*);
Node* rlRotate(Node*);
Node* balance(Node*);
Node* addTree(Node*, string);
void output(Node*);

int main()
{
    struct Node* root = NULL; // Root of tree
    string temp; // Temporary value for user file input

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    while (is >> temp) {
        root = addTree(root, temp);
    }

    cout << setw(10) << "NODE" << setw(10) << "LEFT" << setw(10) << "RIGHT" << setw(10) << "HEIGHT" << setw(10) << "BALANCE" << endl;
    output(root);

}

// Function takes data for node, then creates a new structure, puts the data into the node, then returns the node.
struct Node* getEntry(string value)
{
    struct Node* newNode; // Pointer to new structure
    newNode = new struct Node;
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

// Recursive function that takes a node, then calculates and returns the height of that node
int height(Node* node) {
    int toReturn = 0; // Height
    if (node != NULL) {
        int leftHeight = height(node->left); // Height of left child
        int rightHeight = height(node->right); // Height of right child
        int maxHeight = max(leftHeight, rightHeight); // Maximum height of both children
        toReturn = maxHeight + 1;
    }
    return toReturn;
}

// Function takes a node, then calculates and returns the balance of that node
int difference(Node* node) {
    int leftHeight = height(node->left); // Height of left child
    int rightHeight = height(node->right); // Height of right child
    int toReturn = leftHeight - rightHeight; // Represents the balance, value to be returned
    return toReturn;
}

// Function takes a node and performs a right-right rotate on that node
Node* rrRotate(Node* parent) {
    Node* node; // Pointer to new node that will be rotated and returned
    node = parent->right;
    parent->right = node->left;
    node->left = parent;
    return node;
}

// Function takes a node and performs a left-left rotate on that node
Node* llRotate(Node* parent) {
    Node* node; // Pointer to new node that will be rotated and returned
    node = parent->left;
    parent->left = node->right;
    node->right = parent;
    return node;
}

// Function takes a node and performs a left-right rotate on that node
Node* lrRotate(Node* parent) {
    Node* node; // Pointer to new node that will be rotated and returned
    node = parent->left;
    parent->left = rrRotate(node);
    return llRotate(parent);
}

// Function takes a node and performs a right-left rotate on that node
Node* rlRotate(Node* parent) {
    Node* node; // Pointer to new node that will be rotated and returned
    node = parent->right;
    parent->right = llRotate(node);
    return rrRotate(parent);
}

// Function takes root of the tree and determines whether or not it needs to be balanced. If it does need to be balanced, function will return the balanced tree.
Node* balance(Node* node) {
    int balanceFactor = difference(node); // Represents balance of current node
    if (balanceFactor > 1) {
        if (difference(node->left) > 0) {
            node = llRotate(node);
        }
        else {
            node = lrRotate(node);
        }
    }
    else if (balanceFactor < -1) {
        if (difference(node->right) > 0) {
            node = rlRotate(node);
        }
        else {
            node = rrRotate(node);
        }
    }
    return node;

}

// Recursive function that finds a spot for a new node and inserts it, then returns the updated and balanced tree.
Node* addTree(Node* node, // Root of tree
    string value) // String, data associated with new node
{
    if (node == NULL) {
        node = getEntry(value);
        return node;
    }

    if (value < node->value) {
        node->left = addTree(node->left, value);
        node = balance(node);
    }
    else if (value > node->value) {
        node->right = addTree(node->right, value);
        node = balance(node);
    }

    return node;
}

// Recursive function that outputs an entire tree starting from the root, which is the parameter. Output uses inorder traversal.
void output(Node* node) {
    if (node == NULL) {
        return;
    }
    output(node->left);

    // Output
    cout << fixed << right;
    cout << setw(10) << node->value;

    if (node->left == NULL) {
        cout << setw(10) << "null";
    }
    else {
        cout << setw(10) << node->left->value;
    }

    if (node->right == NULL) {
        cout << setw(10) << "null";
    }
    else {
        cout << setw(10) << node->right->value;
    }

    cout << setw(10) << height(node);

    cout << setw(10) << difference(node);

    cout << endl;

    output(node->right);
}


