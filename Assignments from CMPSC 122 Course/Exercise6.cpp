// Zach Mello
// 4/30/22
// Generates random words from a training set

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 27; // 26 chars + 1
const int WORDSIZE = 25; // max word size

int main()
{
    char cArray[SIZE]; // array of characters in set

    int firstChars[SIZE] = { 0 }; // array of first character multiplicities
    int transArray[SIZE][SIZE] = { 0 }; // transition array of multiplicities
    char word[WORDSIZE] = {}; // word being built

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    int iterations; // User input, number of times a random word will be generated
    cout << "Enter number of iterations you would like: ";
    cin >> iterations;

    ofstream os;
    os.open("Ex6output.txt");

    int sumFirst = 0; // Represents number of times any character comes first in the training set
    int charCount; // User input, number of characters from set
    int wordCount; // User input, number of words from set
    string tWords; // Temporary placeholder for training words from input file

    is >> charCount;
    for (int a = 0; a < charCount; a++) {
        is >> cArray[a];
    }
    is >> wordCount;
    while (is >> tWords) {
        for (int i = 0; i < tWords.length(); i++) {
            for (int j = 0; j < charCount; j++) {
                if (tWords[i] == cArray[j]) {
                    if (i == 0) {
                        firstChars[j]++;
                        transArray[charCount][j]++;
                    }
                    if (i == (tWords.length() - 1)) {
                        transArray[j][charCount]++;
                    }
                    else {
                        for (int k = 0; k < charCount; k++) {
                            if (tWords[i + 1] == cArray[k]) {
                                transArray[j][k]++;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int z = 0; z < charCount; z++) {
         sumFirst += transArray[z][charCount];
    }
    transArray[charCount][charCount] = sumFirst;

    int count; // Placeholder for random number generated
    int prev; // Previous character in word
    int wordLength; // Length of current word
    bool endWord = false; // If true, word will be ended
    srand(time(NULL)); // Seed random number generator

    for (int b = 0; b < iterations; b++) {
        wordLength = 0;
        endWord = false;
        count = rand() % sumFirst + 1;
        for (int i = 0; i < charCount; i++) {
            count -= firstChars[i];
            if (count <= 0) {
                word[0] = cArray[i];
                prev = i;
                break;
            }
            if (i == (charCount - 1)) {
                i = 0;
            }
        }
        wordLength = 1;
        for (int j = 1; j < WORDSIZE; j++) {
            count = rand() % sumFirst + 1;
            for (int i = 0; i <= charCount; i++) {
                count -= transArray[prev][i];
                if (count <= 0) {
                    if (i == charCount) {
                        endWord = true;
                    }
                    else {
                        word[j] = cArray[i];
                        wordLength++;
                        prev = i;
                    }
                    break;
                }
                if (i == charCount) {
                    i = 0;
                }
            }
            if (endWord == true) {
                break;
            }
        }

        for (int i = 0; i < wordLength; i++) {
            os << word[i];
        }
        os << endl;
    }

    cout << "Name of output file: Ex6output.txt" << endl;

}
