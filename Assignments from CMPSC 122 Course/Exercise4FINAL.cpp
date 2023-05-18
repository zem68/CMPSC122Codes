// Zach Mello
// 3/29/22
// Implements a priority queue for jobs from user input

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct pqEntry {
    string job; // Name of job
    int priority; // Priority index
    struct pqEntry* nextPtr; // Pointer to next queue
};

struct pqEntry* getEntry()
{
    struct pqEntry* newPtr; // Pointer to the new structure
    newPtr = new struct pqEntry;
    newPtr->job = "";
    newPtr->priority = 0;
    newPtr->nextPtr = NULL;
    return newPtr;
}

void jobInsert(pqEntry*&, pqEntry*&, pqEntry*&, pqEntry*&, pqEntry*&);

int main()
{
    struct pqEntry* headPtr; // Pointer to first structure
    struct pqEntry* auxPtr; // Pointer for first auxiliary structure
    struct pqEntry* tailPtr; // Pointer to last structure
    headPtr = NULL;
    auxPtr = NULL;
    tailPtr = NULL;

    struct pqEntry* aux2Ptr; // Pointer for a second auxiliary structure, to help insert queues
    aux2Ptr = NULL;
    struct pqEntry* aux3Ptr; // Pointer for a third auxiliary structure, to help insert queues
    aux3Ptr = NULL;

    string jobInput; // Temporary value for name of job
    int priorityInput; // Temporary value for priority

    int count = 0;

    cout << "Enter a priority from 0-10: ";
    cin >> priorityInput;
    cout << endl;
    cout << "Enter name of job: ";
    getline(cin, jobInput);
    getline(cin, jobInput);
    cout << endl;

    auxPtr = getEntry();
    auxPtr->job = jobInput;
    auxPtr->priority = priorityInput;
    headPtr = tailPtr = auxPtr;
    count++;

    cout << "Enter a priority from 0-10 (Enter -1 to exit): ";
    cin >> priorityInput;
    cout << endl;
    while (count < 25 && priorityInput >= 0) {
        cout << "Enter name of job: ";
        getline(cin, jobInput);
        getline(cin, jobInput);
        cout << endl;
        count++;

        auxPtr = getEntry();
        auxPtr->job = jobInput;
        auxPtr->priority = priorityInput;

        aux2Ptr = headPtr->nextPtr;
        aux3Ptr = headPtr;
        jobInsert(headPtr, tailPtr, auxPtr, aux2Ptr, aux3Ptr);


        if (count < 25) {
            cout << "Enter a priority from 0-10 (Enter -1 to exit): ";
            cin >> priorityInput;
            cout << endl;
        }
    }

    auxPtr = headPtr;
    while (auxPtr != NULL) {
        cout << "Priority: " << auxPtr->priority << " Job: " << auxPtr->job << endl;
        auxPtr = auxPtr->nextPtr;
    }
}

// Function inserts new jobs into the linked list using references to linked list pointers

void jobInsert(pqEntry*& headPtr, // Reference to pointer to head of linked list
    pqEntry*& tailPtr, // Reference to pointer to tail of linked list
    pqEntry*& auxPtr, // Reference to pointer to new entry to linked list
    pqEntry*& aux2Ptr, // Reference to helper auxiliary pointer
    pqEntry*& aux3Ptr) // Reference to other helper auxiliary pointer
{ 
    if (auxPtr->priority <= headPtr->priority) {
        auxPtr->nextPtr = headPtr;
        headPtr = auxPtr;
        return;
    }
    else if (auxPtr->priority >= tailPtr->priority) {
        tailPtr->nextPtr = auxPtr;
        tailPtr = auxPtr;
        return;
    }
    else {
        while (aux2Ptr != NULL) {
            if (auxPtr->priority < aux2Ptr->priority) {
                auxPtr->nextPtr = aux2Ptr;
                aux3Ptr->nextPtr = auxPtr;
                return;
            }
            aux2Ptr = aux2Ptr->nextPtr;
            aux3Ptr = aux3Ptr->nextPtr;
        }
    }
}