// Zach Mello
// 2/17/22
// Prompts the user to enter an unsigned integer in base 10 and reverses its format from little to big endian, or vice versa

#include <iostream>
using namespace std;

const int INTSIZE = 4; // in bytes
const int BYTESIZE = 8; // in bits
const int NIBSIZE = 4; // nibble, in bits

union integer4 {
    unsigned int intrep;
    unsigned char byterep[INTSIZE];
};

void prHex(unsigned char);
void prBin(unsigned char);

int main()
{
    integer4 un; // Type for user input
    char temp; // Temporary value for swapping, will change integer to reverse endian

    cout << "Enter an unsigned integer in base 10: ";
    cin >> un.intrep;


    cout << "In hex: " << endl;
    for (int q = 0; q < INTSIZE; q++) {

        prHex(un.byterep[q]);
    }
    cout << endl;
    cout << "In binary: " << endl;
    for (int qq = 0; qq < INTSIZE; qq++) {
        prBin(un.byterep[qq]);
    }
    cout << '\n' << endl;



    temp = un.byterep[0];
    un.byterep[0] = un.byterep[3];
    un.byterep[3] = temp;

    temp = un.byterep[1];
    un.byterep[1] = un.byterep[2];
    un.byterep[2] = temp;



    cout << "Reverse Endian: " << endl;
    cout << "In hex: " << endl;
    for (int q = 0; q < INTSIZE; q++) {

        prHex(un.byterep[q]);
    }
    cout << endl;
    cout << "In binary: " << endl;
    for (int qq = 0; qq < INTSIZE; qq++) {
        prBin(un.byterep[qq]);
    }
    cout << endl;
}

// Function prints unsigned char parameter in hexadecimal format
void prHex(unsigned char input) {
    unsigned int int1 = int(input); // Parameter in integer form
    char output1[17] = "0123456789ABCDEF"; // User output, represents the numbers in hexadecimal

    for (int i = 1; i >= 0; i--) {
            cout << output1[((int1 >> i * 4) & 0xF)];
    }

    cout << ' ';

    return;
}

// Function prints unsigned char parameter in binary format
void prBin(unsigned char input) {
    unsigned char mask = 0x80; // Equivalent to 10000000 in binary, will check if first digit of parameter is 1 as well

    for (int i = 0; i < BYTESIZE; i++) {
        if ((input << i) & mask) {
            cout << '1';
        }
        else {
            cout << '0';
        }
    }
    cout << ' ';
    return;
}

