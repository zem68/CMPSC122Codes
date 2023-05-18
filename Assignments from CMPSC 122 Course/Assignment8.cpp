// Zach Mello 
// 3/3/22
// Program reads integers from user input into a linked list and removes duplicates by queueing and dequeueing

#include <iostream>
#include <cstdlib>
using namespace std;

struct qEntry
{
    int value; // The integer read in
    struct qEntry* nextPtr; // pointer to the next structure
};

struct qEntry* getEntry()
{
    struct qEntry* newPtr; // Pointer to the new structure
    newPtr = new struct qEntry;

    newPtr->value = 0;
    newPtr->nextPtr = NULL;
    return newPtr;
}

int main()
{
    struct qEntry* headPtr; // Pointer to first structure
    struct qEntry* auxPtr; // Pointer to auxiliary structure
    struct qEntry* tailPtr; // Pointer to last structure
    headPtr = NULL;
    auxPtr = NULL;
    tailPtr = NULL;
    int input; // Temporary value for user input
    bool print; // Boolean to check whether dequeued integer should print or not, depending on if it is a duplicate
    
    cout << "Enter first integer: ";
    cin >> input;

    auxPtr = getEntry();
    auxPtr->value = input;
    headPtr = tailPtr = auxPtr;
    int counter = 1;

    cout << "Enter next integer (Enter 0 or negative integer to quit): ";
    cin >> input;
    

    while ((input > 0) && (counter < 25)) {
        auxPtr = getEntry();
        auxPtr->value = input;
        tailPtr->nextPtr = auxPtr;
        tailPtr = auxPtr;

        counter++;
        if (counter < 25) {
            cout << "Enter next integer (Enter 0 or negative integer to quit): ";
            cin >> input;
        }
    }

    cout << endl;

    auxPtr = headPtr;
    while (auxPtr != NULL) {
        print = true;

        for (int j = 1; j < counter; j++) {
            auxPtr = auxPtr->nextPtr;
            if (headPtr->value == auxPtr->value) {
                print = false;
                break;
            }
        }
        if (print == true) {
            cout << headPtr->value << ' ';
        }

        headPtr = headPtr->nextPtr;
        auxPtr = headPtr;
        counter--;
    }
    
    cout << endl;
}

