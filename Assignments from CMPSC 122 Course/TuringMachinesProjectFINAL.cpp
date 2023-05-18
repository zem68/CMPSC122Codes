// Zach Mello
// 4/21/22
// Program simulates a Turing Machine using data from an input file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const char BLANK = 'B'; // Represents blank value
const char ZERO = '0'; // Represents 0 value
const char ONE = '1'; // Represents 1 value
const char STAR = '*'; // Represents * value
const char LEFT = 'L'; // Represents left command
const char RIGHT = 'R'; // Represents left command
const int MAXTAPE = 100; // Maximum length of tape
const int MAXSTATES = 25; // Maximum number of states
const short STARTPOS = 40; // Starting position on tape
const char STARTSTATE = ZERO; // Starting state

struct stateTrans {
    char state; // Current state
    char readChar; // Character read in
    char nextState; // Next State
    char writeChar; // Character wrote in
    char move; // Which direction to move
};

int main()
{
    stateTrans states[MAXSTATES]; // Represents the states of the Turing Machine
    char tape[MAXTAPE]; // Represents the tape for the Turing Machine
    for (int i = 0; i < MAXTAPE; i++) {
        tape[i] = BLANK;
    }
    string tapeValues; // User input, temprary value for tape from input file
    string values; // User input, temprary value for states from input file

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    is >> tapeValues;
    for (int i = 0; i < tapeValues.length(); i++) {
        if ((i + STARTPOS) >= MAXTAPE) {
            break;
        }
        else {
            tape[i + STARTPOS] = tapeValues[i];
        }
    }

    int stateCounter = 0; // Counts number of states
    while ((is >> values) && (stateCounter < MAXSTATES)) {
        states[stateCounter].state = values[0];
        states[stateCounter].readChar = values[1];
        states[stateCounter].nextState = values[2];
        states[stateCounter].writeChar = values[3];
        states[stateCounter].move = values[4];
        stateCounter++;
    }

    int currentPosition = STARTPOS; // Current position of Turing Machine, starts at STARTPOS
    char currentState = STARTSTATE; // Current state of Turing Machine, starts at 0

    // Output before execution
    cout << fixed << right;
    cout << "Tape starts at " << STARTPOS << endl;
    cout << "Length = " << tapeValues.length() << endl;
    cout << "Highlights position " << currentPosition << endl;
    cout << "Tape = " << endl;
    cout << setw(4) << tape[STARTPOS - 1];
    for (int i = 0; i <= tapeValues.length(); i++) {
        if ((STARTPOS + i) == currentPosition) {
            cout << setw(4) << '|' << tape[STARTPOS + i] << '|';
        }
        else {
            cout << setw(4) << tape[STARTPOS + i];
        }
    }
    cout << endl;
    for (int i = 0; i < stateCounter; i++) {
        cout << states[i].state << ' ';
        cout << states[i].readChar << ' ';
        cout << states[i].nextState << ' ';
        cout << states[i].writeChar << ' ';
        cout << states[i].move << ' ';
        cout << endl;
    }
    cout << '\n' << endl;



    bool breaker = true; // If true, while loop will break and Turing Machine will end

    int currentLine; // Keeps value of current state line

    while (true) {
        for (int i = 0; i < stateCounter; i++) {
            if (currentState == states[i].state) {
                if (tape[currentPosition] == states[i].readChar) {
                    currentLine = i;
                    breaker = false;
                    break;
                }
            }
        }

        if (breaker == true) {
            break;
        }
        else {
            currentState = states[currentLine].nextState;
            tape[currentPosition] = states[currentLine].writeChar;
            if (states[currentLine].move == LEFT) {
                currentPosition--;
            }
            else if (states[currentLine].move == RIGHT) {
                currentPosition++;
            }

            breaker = true;
        }
    }

    // Output after execution
    cout << "Execution halts in state " << currentState << endl;
    cout << "Tape starts at " << STARTPOS << endl;
    cout << "Length = " << tapeValues.length() << endl;
    cout << "Highlights position " << currentPosition << endl;
    cout << "Tape = " << endl;
    if ((STARTPOS - 1) == currentPosition) {
        cout << setw(4) << '|' << tape[STARTPOS - 1] << '|';
    }
    else {
        cout << setw(4) << tape[STARTPOS - 1];
    }
    for (int i = 0; i <= tapeValues.length(); i++) {
        if ((STARTPOS + i) == currentPosition) {
            cout << setw(4) << '|' << tape[STARTPOS + i] << '|';
        }
        else {
            cout << setw(4) << tape[STARTPOS + i];
        }
    }
    cout << endl;

}
