// Zach Mello
// 3/15/22
// Program prompts the user for a string and either validates it or not according to the FSM

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void val_ID(char*&, int&);
void val_Num(char*&, int&);

int main()
{
    char array[100]; // User input, array of FSM code up to 100 characters
    char* arrayPtr; // Pointer to array of FSM code
    int state = 0; // 0 = START, 1 = BUILD_ID, 2 = DIGITS, 3 = NUMBER, 4 = IDENTIFIER, 5 = END, 6 = ERROR
    
    cout << "Enter the FSM code (Up to 100 characters): ";
    cin.getline(array, 100);

    arrayPtr = array;

    while ((state != 5) && (state != 6)) {
        if (isdigit(*arrayPtr)) {
            state = 2;
            val_Num(arrayPtr, state);
        }
        else if (isalpha(*arrayPtr)) {
            state = 1;
            val_ID(arrayPtr, state);
        }
        else if (*arrayPtr == '.') {
            state = 5;
        }
        else {
            state = 6;
        }
    }
    
    if (state == 6) {
        cout << "Invalid string beginning at: " << arrayPtr << endl;
    }
    else {
        cout << "Output valid." << endl;
    }
}

// Takes a reference to the array pointer and a reference to the state, and checks if identifier from array is valid while adjusting parameters accordingly
void val_ID(char*& arrayPtr, int& state) {
    char* savePtr; // Saves the original array pointer in case the identifier is invalid
    savePtr = arrayPtr;
    string output = ""; // User output of identifier
    while ((isalpha(*arrayPtr)) || (isdigit(*arrayPtr)) || (*arrayPtr == '_')) {
        output += *arrayPtr;
        arrayPtr++;
    }

    if (*arrayPtr == ',') {
        arrayPtr++;
        state = 0;
        cout << fixed << left << setw(10) << output << "Identifier" << endl;
    }
    else {
        state = 6;
        arrayPtr = savePtr;
    }
    return;
}

// Takes a reference to the array pointer and a reference to the state, and checks if positive integer from array is valid while adjusting parameters accordingly
void val_Num(char*& arrayPtr, int& state) {
    char* savePtr; // Saves the original array pointer in case the integer is invalid
    savePtr = arrayPtr;
    string output = ""; // User output of positive integer
    while (isdigit(*arrayPtr)) {
        output += *arrayPtr;
        arrayPtr++;
    }

    if (*arrayPtr == ',') {
        arrayPtr++;
        state = 0;
        cout << fixed << left << setw(10) << output << "Positive integer" << endl;
    }
    else {
        state = 6;
        arrayPtr = savePtr;
    }
    return;
}