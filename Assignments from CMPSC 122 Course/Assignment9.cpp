// Zach Mello
// 3/17/22
// Takes a list of names from an input file and uses a hash table to format and output names

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 256; // Maximum size of hash table

struct hEntry
{
    bool occupied = false; // True only if occupied
    string name = ""; // Name data, if occupied
    struct hEntry* nextPtr = NULL; // pointer to the next structure
};

int main()
{
    struct hEntry hashTable[MAXSIZE]; // The hash table linked list
    struct hEntry* auxPtr; // Pointer to auxiliary structure
    struct hEntry* newPtr; // Pointer to the new structure
    unsigned char key; // Hash table key
    string fullName; // Temporary value for full name

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    while (getline(is, fullName)) {
        key = 0;
        for (int i = 0; i < fullName.length(); i++) {
            key ^= fullName[i];
        }

        if (hashTable[key].occupied == false) {
            hashTable[key].occupied = true;
            hashTable[key].name = fullName;
            hashTable[key].nextPtr = NULL;
        }
        else {
            newPtr = new struct hEntry;
            newPtr->name = fullName;
            newPtr->nextPtr = NULL;
            newPtr->occupied = true;

            auxPtr = &hashTable[key];

            while (auxPtr->nextPtr != NULL) {
                auxPtr = auxPtr->nextPtr;
            }
            auxPtr->nextPtr = newPtr;
        }
    }

    is.close();
    ofstream os("Assign9os.txt");
    cout << "Output file: Assign9os.txt" << endl;

    for (int i = 0; i < MAXSIZE; i++) {
        auxPtr = &hashTable[i];
        if (hashTable[i].occupied == true) {
            os << "Slot " << i << " is occupied with" << endl;
            
            do {
                os << auxPtr->name << '\t';
                auxPtr = auxPtr->nextPtr;
            } while (auxPtr != NULL);
            os << endl;
        }
        
    }
}
