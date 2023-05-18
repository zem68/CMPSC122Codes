// Zach Mello
// 2/15/22
// Modularized program that will recursively generate all the permutations of any given n distinct objects

#include <iostream>
#include <fstream>
using namespace std;


void perm(char*, // Contains all objects
    int, // Index of 1st object
    int, // Index of last object
    ofstream&, // Reference to the open output file
    int&); // Reference to the output number


int main()
{
    char objects[6]; // Array of all objects
    int n; // n number of distinct objects

    cout << "Enter number of characters to enter: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int y = 0; y < n; y++) {
        cin >> objects[y];
    }

    ofstream os;
    os.open("OutputPermutations.txt");

    int osNum = 1; // Number of permutations for output

    perm(objects, 0, (n - 1), os, osNum);

    cout << "Output file: OutputPermutations.txt" << endl;
}


// Recursive function that finds and outputs all permutations of characters in obj
void perm(char* obj, // Contains all objects
    int s, // Index of 1st object
    int n, // Index of last object
    ofstream& os, // Reference to the open output file
    int& osNum) { // Reference to the output number
    char temp; // Temporary value for swapping

    if (s == n) {
        os << "Permutation " << osNum << ":";
        for (int o = 0; o <= n; o++) {
            os << ' ' << obj[o];
        }
        os << endl;
        osNum++;
    }
    else {
        for (int i = s; i <= n; i++) {
            temp = obj[s];
            obj[s] = obj[i];
            obj[i] = temp;

            perm(obj, (s + 1), n, os, osNum);

            temp = obj[s];
            obj[s] = obj[i];
            obj[i] = temp;
        }
    }
    return;
}