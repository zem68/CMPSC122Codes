// Zach Mello
// 1/27/22
// Program prints table of ASCII values for the characters in the ASCII character set from 33 to 126

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    cout << fixed << right << showbase;
    cout << setw(8) << "Decimal" << setw(8) << "Octal" << setw(13) << "Hexadecimal" << setw(18) << "ASCII Character" << endl;
    for (int i = 33; i <= 126; i++) {
        cout << setw(8) << dec << i << setw(8) << oct << i << setw(13) << hex << i <<  setw(18) << char(i) << endl;
    }
}

