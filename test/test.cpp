#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string encryptToMorse(const string& text) { // Метод для зашифровки
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

    string encryptedCode;

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

string encryptFromMorse(const string& code) { // Метод для расшифровки
    map<string, char> morseCode = {
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
        {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
        {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
        {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
        {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
        {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
        {"-.--", 'Y'}, {"--..", 'Z'},
        {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},
        {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},
        {"----.", '9'}, {"-----", '0'}
    };

    string encryptedText;
    stringstream ss(code);
    string morseSymbol;
    vector<string> words;

    while (getline(ss, morseSymbol, ' ')) {
        if (morseSymbol.empty()) {
            if (!words.empty() && words.back() != " ") {
                words.push_back(" ");
            }
        }
        else {
            words.push_back(morseSymbol);
        }
    }

    for (const auto& word : words) {
        if (word == " ") {
            encryptedText += " ";
        }
        else if (morseCode.find(word) != morseCode.end()) {
            encryptedText += morseCode[word];
        }
    }

    return encryptedText;
}


int main() {
    cout << "Choose to morse or unmorse (1/2): ";
    string choose;
    cin >> choose;
    cin.ignore(); // Игнорировать оставшийся символ новой строки

    if (choose == "1") {
        string text;
        cout << "Enter text for morse coding: ";
        getline(cin, text);

        string morseText = encryptToMorse(text);

        cout << "Morse code: " << morseText << endl;
    }
    else if (choose == "2") {
        string code;
        cout << "Enter code for morse decoding: ";
        getline(cin, code);

        string morseText = encryptFromMorse(code);

        cout << "Text: " << morseText << endl;
    }

    return 0;
}
