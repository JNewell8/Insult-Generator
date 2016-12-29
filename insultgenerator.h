#pragma once

#include <string>
#include <vector>

using namespace std;

class FileException {
public:
	// FileException Constructor (message: error message)
	FileException(const string& message);
	// Outputs the error message as a string
	string& what();
private:
	// The error message
	string message;
};

class NumInsultsOutOfBounds {
public:
	// FileException Constructor (message: error message)
	NumInsultsOutOfBounds(const string& message);
	// Outputs the error message as a string
	string& what();
private:
	// The error message
	string message;
};

class InsultGenerator {
public:
	// InsultGenerator constructor (sets the length of the list to be 0)
	InsultGenerator();
	/* Initializes the object by opening the text file with the insult list and loading it into 3
	 	 columns. Throws an exception if the file cannot be opened */
	void initialize();
	// Outputs a string in the form of a Shakesperian insult
	string talkToMe() const;
	// Generates a vector of Shakesperian insults to the size specified
	vector<string> generate(const int size) const;
	// Generates a .txt document with the name 'saveFile' with Shakesperian insults to the size specified
	void generateAndSave(const string saveFile, const int size) const;
private:
	// Generates a random integer from 0 to max - 1
	int randInt(const int max) const;
	// Writes a Shakesperian insult using specific indexes
	string writeInsult(const int one, const int two, const int three) const;
	// Length of the Shakesperian words list
	int listLength;
	// First column of Shakesperian words
	vector<string> Col1;
	// Second column of Shakesperian words
	vector<string> Col2;
	// Third column of Shakesperian words
	vector<string> Col3;
};
