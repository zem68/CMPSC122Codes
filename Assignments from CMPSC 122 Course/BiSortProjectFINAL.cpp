// Zach Mello 
// 3/1/22
// Program reads integers from input file and binary sorts them into a linked list 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;



struct listMemb
{
    int value; // The integer read in
    struct listMemb* leftPtr; // Pointer to the previous structure
    struct listMemb* rightPtr; // pointer to the next structure
};

struct listMemb* getEntry()
{
    struct listMemb* newPtr; // Pointer to the new structure
    newPtr = new struct listMemb;
    newPtr->value = 0;
    newPtr->rightPtr = NULL;
    newPtr->leftPtr = NULL;
    return newPtr;
}

void output(listMemb*, listMemb*, listMemb*, listMemb*, int, ofstream&);

int main()
{
    struct listMemb* h; // Pointer to first structure
    struct listMemb* x; // Pointer for auxiliary structure
    struct listMemb* t; // Pointer to last structure
    struct listMemb* m; // Pointer to middle of structure
    h = NULL;
    x = NULL;
    t = NULL;
    m = NULL;
    int input; // Temporary value for input file numbers
    int c = 0; // Count of Elements in list
    int midFinder; // Used to re-find the midpoint

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    ofstream os;
    os.open("BiSortOutput.txt");
    char vw; // User input, verbose option for user to see sorting process
    bool view = false; // Boolean to check if user wants to see sorting process
    cout << "Type \'y\' if you want to view every step of sorting process: ";
    cin >> vw;
    if (vw == 'y') {
        view = true;
    }

    is >> input;
    x = getEntry();
    x->value = input;
    h = t = m = x;
    c++;
    if (view == true) {
        output(h, x, t, m, c, os);
    }

    while (is >> input) {
        x = getEntry();
        x->value = input;
        c++;

        if (x->value <= h->value) {
            x->rightPtr = h;
            h->leftPtr = x;
            h = x;
        }
        else if (x->value >= t->value) {
            x->leftPtr = t;
            t->rightPtr = x;
            t = x;
        }
        else if (x->value < m->value) {
            while (m != NULL) {
                m = m->leftPtr;
                if (x->value > m->value) {
                    x->rightPtr = m->rightPtr;
                    m->rightPtr = x;
                    x->leftPtr = m;
                    x->rightPtr->leftPtr = x;
                    break;
                }
            }
        }
        else { // if (x->value > m->value)
            while (m != NULL) {
                m = m->rightPtr;
                if (x->value < m->value) {
                    m = m->leftPtr;
                    x->rightPtr = m->rightPtr;
                    m->rightPtr = x;
                    x->leftPtr = m;
                    x->rightPtr->leftPtr = x;
                    break;
                }
            }
        }

        if (c % 2 == 1) {
            midFinder = (c / 2) + 1;
        }
        else {
            midFinder = c / 2;
        }

        m = h;
        for (int qq = 1; qq < midFinder; qq++) {
            m = m->rightPtr;
        }

        if (view == true) {
            output(h, x, t, m, c, os);
        }
    }

    is.close();

    int newSpace = 5; // Creates space for formatting of value output
    cout << fixed << right;
    cout << "Values:";
    x = h;
    cout << setw(5) << x->value;
    for (int i = 1; i < c; i++) {
        x = x->rightPtr;
        cout << setw(newSpace) << x->value;
        if (((i + 1) % 10 == 0) && (i + 1 != c)) {
            cout << endl;
            newSpace = 12;
        }
        else {
            newSpace = 5;
        }
    }
    cout << endl;
    cout << "c = " << c << endl;
    cout << "h => " << h->value << endl;
    cout << "t => " << t->value << endl;
    cout << "m => " << m->value << endl;
    cout << endl;

    if (view == true) {
        cout << "Output file: BiSortOutput.txt" << endl;
    }

    
}

// Function programs output if user wants to see every step of sorting process
void output(listMemb* h, // Head of linked list
    listMemb* x, // Current input value in linked list
    listMemb* t, // Tail of linked list
    listMemb* m, // Middle of linked list
    int c, // Count of elements in list
    ofstream& os) // Reference to open output file
{
    int newSpace = 5; // Creates space for formatting of value output
    
    os << fixed << right;
    os << "Read x = " << x->value << endl;
    os << "Values:";

    x = h;

    os << setw(5) << x->value;
    for (int i = 1; i < c; i++) {
        x = x->rightPtr;
        os << setw(newSpace) << x->value;
        if (((i + 1) % 10 == 0) && (i + 1 != c)) {
            os << endl;
            newSpace = 12;
        }
        else {
            newSpace = 5;
        }
    }
    os << endl;
    os << "c = " << c << endl;
    os << "h => " << h->value << endl;
    os << "t => " << t->value << endl;
    os << "m => " << m->value << endl;
    os << '\n' << endl;
}