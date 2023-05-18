// Zach Mello
// 2/10/22
// Prompts the user for an English word, phrase, or sentence and then translate the words into Pig Latin

#include <iostream>
#include <string>
using namespace std;


// Takes a single word in the form of a string, and translates it to pig latin, and returns a string of the word in pig latin
string translator(string); // Parameter is the current word that the user wants to translate to pig latin

int main()
{
    char state = 0; // Base parameter required for strtok_s
    char* ptr = &state; // Pointer for rest of words in sentence

    char sentence[201]; // User input, sentence
    cout << "Enter a sentence: ";
    cin.getline(sentence, 201);

    string currWord = ""; // The current word to be translated
    string pigLatin = ""; // User output, in pig latin
    char* tokenPtr; // Pointer for the current sentence

    tokenPtr = strtok_s(sentence, " ", &ptr);

    while (tokenPtr != NULL) {
        currWord = tokenPtr;

        pigLatin += translator(currWord);

        tokenPtr = strtok_s(NULL, " ", &ptr);
    }

    cout << pigLatin << endl;
}

string translator(string string1) {
    int stringLength = string1.length(); // Length of word
    string front = ""; // Front consonants to be added to end with -ay
    string toReturn = ""; // string to be returned, in pig latin

    for (int w = 0; w < stringLength; w++) {
        if ((string1[w] == 'a') || string1[w] == 'A' || string1[w] == 'e' || string1[w] == 'E' || string1[w] == 'i' || string1[w] == 'I' || string1[w] == 'o' || string1[w] == 'O' || string1[w] == 'u' || string1[w] == 'U') {
            toReturn = string1.substr(w, (stringLength - w)) + "-" + front + "ay ";
            return toReturn;
        }
        else {
            front += string1[w];
        }
    }
    return toReturn;
}