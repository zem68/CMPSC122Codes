// Zach Mello
// 2/3/22
// Program is given a 7 digit number, and writes to a file every possible seven letter word corresponding to that number

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


const int ROWSIZE = 10; // Size of array row
const int COLSIZE = 5; // Size of array column
const int NUMSIZE = 8; // Size of phone number array

// Recursive function that outputs every letter combination of a 7 digit phone number
void combine(char*, // user input array
    char[ROWSIZE][COLSIZE], // 2-d array of letters, above
    char*, // array in which to build the output
    int, // index into output array; base case when this = 7
    ofstream&); // reference to the open output file

int main()
{
    char array[NUMSIZE]; // user input
    char letters[ROWSIZE][COLSIZE] = { { '0', '\0', '\0', '\0', '\0' }, // row index 0
                                         { '1', '\0', '\0', '\0', '\0' },// row index 1
                                         { 'A', 'B', 'C', '\0', '\0' }, // row index 2
                                         { 'D', 'E', 'F', '\0', '\0' }, // row index 3
                                         { 'G', 'H', 'I', '\0', '\0' }, // row index 4
                                         { 'J', 'K', 'L', '\0', '\0' }, // row index 5
                                         { 'M', 'N', 'O', '\0', '\0' }, // row index 6
                                         { 'P', 'Q', 'R', 'S', '\0' }, // row index 7
                                         { 'T', 'U', 'V', '\0', '\0' }, // row index 8
                                         { 'W', 'X', 'Y', 'Z', '\0' } }; // row index 9
    char buildArr[NUMSIZE]; // Output Array
    buildArr[7] = '\0';
    int index = 0; // index into output array; base case when = 7

    ofstream os;
    os.open("Outputa4.txt");

    cout << "Enter 7 characters: ";
    for (int o = 0; o < 7; o++) {
        cin >> array[o];
    }
    array[7] = '\0';

    combine(array, letters, buildArr, index, os);

    cout << "Output file: Outputa4.txt" << endl;
}


void combine(char* input, char letters[ROWSIZE][COLSIZE], char* build, int index, ofstream& os) {
    if (index == 7) {
        os << build << endl;
        return;
    }

    int indexNum = (int)input[index] - (int)'0'; // Converts character digit to a row index
    int j = 0; // Counter for loop
    while (letters[indexNum][j] != '\0') {
        build[index] = letters[indexNum][j];
        combine(input, letters, build, (index + 1), os);
        j++;
    }
    return;
}
