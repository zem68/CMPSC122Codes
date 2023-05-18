// Zach Mello
// 4/12/22
/* Program creates a tree for input file data where:
 1) the leftmost string goes into a node;
 2) the middle string goes into the node’s left child; and,
 3) the rightmost string goes into the node’s right child.
 Tree is loaded using preorder traversal and then outputted in postorder traversal.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Node
{
    string value; // Value associated with node
    struct Node* left = NULL; // Pointer to left branch
    struct Node* right = NULL; // Pointer to right branch
};

struct Node* getEntry(string temp)
{
    struct Node* newNode; // Pointer to new structure
    newNode = new struct Node;
    newNode->value = temp;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void search(Node*, Node*&, string);
void output(Node*);

int main()
{
    struct Node* root = NULL; // Root of tree
    struct Node* auxPtr = NULL; // Auxiliary pointer
    string temp; // temporary value for user file input

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    is >> temp;
    root = getEntry(temp);

    is >> temp;
    if (temp != "null") {
        root->left = getEntry(temp);
    }
    is >> temp;
    if (temp != "null") {
        root->right = getEntry(temp);
    }
    while (is >> temp) {
        search(root, auxPtr, temp);
        is >> temp;
        if (temp != "null") {
            auxPtr->left = getEntry(temp);
        }
        is >> temp;
        if (temp != "null") {
            auxPtr->right = getEntry(temp);
        }
    }
    output(root);
    cout << endl;
}

// Recursive function that searches for the correct new spot for new value
void search(Node* node, // Root of tree
    Node*& auxPtr, // Auxiliary pointer, represents spot for new value
    string temp) // New value for tree
{
    if (node->value == temp) {
        auxPtr = node;
        return;
    }
    else if ((node->left == NULL) || (node->right == NULL)) {
        return;
    }
    else {
        search(node->left, auxPtr, temp);
        search(node->right, auxPtr, temp);
    }
}

// Recursive function that takes the root of a tree and outputs all values using postorder traversal
void output(Node* node) // Root of tree
{
    if (node == NULL) {
        return;
    }
    output(node->left);

    output(node->right);

    cout << node->value << " ";
}