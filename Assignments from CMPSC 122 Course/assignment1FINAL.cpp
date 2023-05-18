// Zach Mello 1/14/22
// Program reads integers from input file into a linked list using pointers to structures

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct entry
{
    int value; // The integer read in
    struct entry* nextPtr; // pointer to the next structure
};

struct entry* getEntry()
{
    struct entry* newPtr; // Pointer to the new structure
    newPtr = new struct entry;
    newPtr->value = 0;
    newPtr->nextPtr = NULL;
    return newPtr;
}

int main()
{
    struct entry* firstPtr; // Pointer to first structure
    struct entry* auxPtr; // Pointer for auxiliary structure
    struct entry* lastPtr; // Pointer to last structure
    firstPtr = NULL;
    auxPtr = NULL;
    lastPtr = NULL;
    int input; // Temporary value for input file numbers
    int newlineCount = 0; // Counter for output

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    is >> input;
    auxPtr = getEntry();
    auxPtr->value = input;
    firstPtr = lastPtr = auxPtr;

    while (is >> input) {
        auxPtr = getEntry();
        auxPtr->value = input;
        lastPtr->nextPtr = auxPtr;
        lastPtr = auxPtr;
    }

    is.close();

    auxPtr = firstPtr;
    while (auxPtr != NULL) {
        cout << fixed << right;
        cout << setw(5) << auxPtr->value;
        auxPtr = auxPtr->nextPtr;
        newlineCount += 1;
        if (newlineCount == 10) {
            cout << '\n';
            newlineCount = 0;
        }
    }
    cout << endl;
}

