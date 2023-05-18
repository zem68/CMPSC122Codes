// Zach Mello 
// 2/22/22
// Processes an old master file and creates a new master file using data from a transaction file

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct entry
{
    int accNumMast; // Account# in prev master file
    string firstNameMast; // First Name in prev master file
    string lastNameMast; // Last Name in prev master file
    double balanceMast; // Balance Owed in prev master file

    struct entry* nextPtr; // pointer to the next structure
};

struct entry* getEntry()
{
    struct entry* newPtr; // Pointer to the new structure
    newPtr = new struct entry;
    newPtr->accNumMast = 0;
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
    int input; // Temporary value for account# in prev master file
    string input2; // Temporary value for First Name in prev master file
    string input3; // Temporary value for Last Name in prev master file
    double input4; // Temporary value for Balance Owed in prev master file
    int input5; // Temporary value for account# in transaction file
    double input6; // Temporary value for Amount in transaction file

    int mastCounter = 0; // Counter for amount of accounts in previous master file

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of Previous Master File: ";
    cin >> fileName;
    is.open(fileName);

    if (is.fail()) {
        cout << "Cannot open " << fileName << endl;
        return 1;
    }

    is >> input >> input2 >> input3 >> input4;
    auxPtr = getEntry();
    auxPtr->accNumMast = input;
    auxPtr->firstNameMast = input2;
    auxPtr->lastNameMast = input3;
    auxPtr->balanceMast = input4;
    mastCounter++;
    firstPtr = lastPtr = auxPtr;

    while (is >> input >> input2 >> input3 >> input4) {
        auxPtr = getEntry();
        auxPtr->accNumMast = input;
        auxPtr->firstNameMast = input2;
        auxPtr->lastNameMast = input3;
        auxPtr->balanceMast = input4;
        mastCounter++;
        lastPtr->nextPtr = auxPtr;
        lastPtr = auxPtr;
    }

    is.close();

    cout << "Enter name of Transaction File: ";
    cin >> fileName;
    is.open(fileName);

    if (is.fail()) {
        cout << "Cannot open " << fileName << endl;
        return 1;
    }

    while (is >> input5 >> input6) {
        auxPtr = firstPtr;
        for (int i = 0; i <= mastCounter; i++) {
            if (i == mastCounter) {
                cout << "Unmatched record for account #" << input5 << endl;
                break;
            }

            if (input5 == auxPtr->accNumMast) {
                auxPtr->balanceMast += input6;
                break;
            }
            
            auxPtr = auxPtr->nextPtr;
        }
    }
    
    is.close();

    ofstream os;
    os.open("NewMasterFile.txt");

    auxPtr = firstPtr;
    while (auxPtr != NULL) {
        os << fixed << right;
        os << auxPtr->accNumMast << ' ' << auxPtr->firstNameMast << ' ' << auxPtr->lastNameMast << ' ' << setprecision(2) << auxPtr->balanceMast << endl;
        auxPtr = auxPtr->nextPtr;
    }

    cout << "Output File: NewMasterFile.txt" << endl;
}


