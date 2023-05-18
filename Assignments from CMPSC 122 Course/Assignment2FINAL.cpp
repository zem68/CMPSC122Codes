// Zach Mello
// 1/20/22
// Uses recursive programming and Euclid's algorithm to find GCD of 2 positive integers

#include <iostream>
using namespace std;

int GCD(int, int);

int main()
{
    int num1 = 0; // Pair of positive integers, num1 will be greater integer
    int num2 = 0; // Pair of positive integers
    int temp; // Temporary value for switching num1 and num2
    int opGCD; // User output, the GCD

    cout << "Enter 2 positive integers seperated by a space: ";
    while ((num1 <= 0) || (num2 <= 0)) {
        cin >> num1 >> num2;
        if ((num1 <= 0) || (num2 <= 0)) {
            cout << "Error: Enter 2 positive integers seperated by a space: ";
        }
    }

    if (num2 > num1) {
        temp = num2;
        num2 = num1;
        num1 = temp;
    }

    opGCD = GCD(num1, num2);
    cout << "The greatest common divisor of " << num1 << " and " << num2 << " is " << opGCD << "." << endl;
}


/* Recursive function that finds and returns the greatest common divisor between
integer a (the greater number) and integer b (the smaller number).
*/
int GCD(int a, int b) {
    int rem; // Remainder of 2 nums
    rem = a % b;
    if (rem == 0) {
        return b;
    }
    return GCD(b, rem);
}