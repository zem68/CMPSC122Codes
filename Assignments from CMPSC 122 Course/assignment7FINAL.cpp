// Zach Mello
// 2/24/22
// Stack based application used to recognise palindromes. Program should ignore spaces, punctuation, and alpha cases

#include <iostream>
#include <string>

using namespace std;

char stack[25]; // Universal, stack containing 25 slots
unsigned int sp = 0; // Universal, pointer for stack
char pop();
void push(char);

int main()
{
    string temp; // User input, palindrome in string form
    char reg; // Register, value to be pushed into and popped from stack
    bool palindromeCheck = true; // Boolean, true if string is palindrome, false if isn't

    cout << "Enter a string (less than 25 characters): ";
    getline(cin, temp);

    for (int j = 0; j < temp.length(); j++) {
        reg = temp[j];
        if ((reg >= 97) && (reg <= 122)) {
            push(reg);
        }
        else if ((reg >= 48) && (reg <= 57)) {
            push(reg);
        }
        else if ((reg >= 65) && (reg <= 90)) {
            push(int(reg) + 32);
        }
    }

    reg = pop();
    for (int i = 0; i < sp; i++) {
        if (reg != stack[i]) {
            palindromeCheck = false;
            break;
        }
        reg = pop();
    }

    if (palindromeCheck == true) {
        cout << temp << " is a palindrome." << endl;
    }
    else {
        cout << temp << " is not a palindrome." << endl;
    }
}

// Character will be popped from stack and returned to the register in main
char pop() {
    sp--;
    return stack[sp];
}

// New character char1 will be pushed into stack
void push(char char1) {
    stack[sp] = char1;
    sp++;
    return;
}

