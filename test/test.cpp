#include <iostream>
#include <map>
#include <string>

using namespace std;

string encryptToMorse(const string& text) {
    map<char, string> morseCode = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."},
        {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
        {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
        {'9', "----."}, {'0', "-----"}
    };

    string encryptedCode = "";

    for (char c : text) {
        c = toupper(c);

        if (morseCode.find(c) != morseCode.end()) {
            encryptedCode += morseCode[c] + " ";
        }

        else if (c == ' ') {
            encryptedCode += "  ";
        }
    }
    return encryptedCode;
}

int main()
{
    string text;
    cout << "Enter text for morse coding: ";
    getline(cin, text);

    string morseText = encryptToMorse(text);

    cout << "Morse code: " << morseText << endl;

    return 0;
}