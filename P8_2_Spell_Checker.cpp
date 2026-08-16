/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class:       CSC 242
** Assignment:  P8.2
** File:        source.cpp
** Description: Reads a dictionary file and prints words from another file
**              that are not found in the dictionary.
**
** Author:      [Brittany Burson]
** Date:        [08/15/2026]
** -------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Team Member: Brittany Burson
// Loads all words from the dictionary file into a vector.
vector<string> loadDictionary(const string& fileName)
{
    vector<string> words;
    ifstream dictionaryFile(fileName);
    string word;

    if (!dictionaryFile)
    {
        return words;
    }

    while (dictionaryFile >> word)
    {
        // Convert dictionary words to lowercase.
        for (char& ch : word)
        {
            ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        }

        words.push_back(word);
    }

    return words;
}

// Team Member: Brittany Burson
// Removes punctuation and converts a word to lowercase.
string normalizeWord(const string& word)
{
    string cleanedWord;

    for (char ch : word)
    {
        if (isalpha(static_cast<unsigned char>(ch)) || ch == '\'')
        {
            cleanedWord += static_cast<char>(
                tolower(static_cast<unsigned char>(ch))
                );
        }
    }

    return cleanedWord;
}

// Team Member: Brittany Burson
// Checks whether a word exists in the dictionary vector.
bool wordExists(const string& word, const vector<string>& words)
{
    for (const string& dictionaryWord : words)
    {
        if (dictionaryWord == word)
        {
            return true;
        }
    }

    return false;
}

// Team Member:Brittany Burson
// Reads the file to be checked and prints words not found in the dictionary.
void checkFile(const string& fileName, const vector<string>& words)
{
    ifstream inputFile(fileName);
    string word;

    if (!inputFile)
    {
        cout << "The file to be checked could not be opened." << endl;
        return;
    }

    cout << endl;
    cout << "Words not found in the dictionary:" << endl;

    while (inputFile >> word)
    {
        string cleanedWord = normalizeWord(word);

        if (!cleanedWord.empty() && !wordExists(cleanedWord, words))
        {
            cout << cleanedWord << endl;
        }
    }
}

int main()
{
    string dictionaryFileName;
    string checkFileName;

    cout << "Spell Checker Program" << endl;
    cout << "Enter dictionary file name: ";
    getline(cin, dictionaryFileName);

    cout << "Enter file name to spell check: ";
    getline(cin, checkFileName);

    vector<string> words = loadDictionary(dictionaryFileName);

    if (words.empty())
    {
        cout << "The dictionary file could not be loaded." << endl;
        return 1;
    }

    checkFile(checkFileName, words);

    return 0;
}
