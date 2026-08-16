# P8.2 Spell Checker

## Description

This project is a C++ spell checker based on Chapter 8, Programming Project P8.2 from *Big C++: Late Objects, Enhanced*.

The program reads words from a dictionary file and stores them in a vector. It then reads another text file and checks each word against the dictionary. If a word is not found in the dictionary, the program displays it on the screen.

## Files

- `source.cpp` - Contains the C++ program and functions used for the spell checker.
- `dictionary.txt` - Contains the list of words used by the program as the dictionary.
- `test.txt` - Contains sample text used to test the spell checker.
- `P8_2_Spell_Checker_Pseudocode.docx` - Contains the pseudocode and design/functional information for the program.

## How It Works

The user enters the name of the dictionary file and the file that they want to check. The program loads the dictionary into a vector and then checks each word in the test file. Words that are not found in the dictionary are displayed as misspelled or unknown words.

## Course

CSC 242 - C++

## Assignment

Chapter 8 - P8.2 Spell Checker
