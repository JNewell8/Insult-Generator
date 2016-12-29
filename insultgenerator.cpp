#include "insultgenerator.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<stdlib.h>

using namespace std;

FileException::FileException(const string& message) : message(message) {}
string& FileException::what() { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}
string& NumInsultsOutOfBounds::what() { return message; }

InsultGenerator::InsultGenerator() : listLength(0) {}

int InsultGenerator::randInt(int const max) const {
	return rand() % max;
}// end randInt

string InsultGenerator::writeInsult(const int one, const int two, const int three) const {
	return	"Thou " +
			Col1.at(one) + " " +
			Col2.at(two) + " " +
			Col3.at(three) + "!";
}// end writeInsult

void InsultGenerator::initialize() {
	ifstream fileIn("InsultsSource.txt");
	if (fileIn.fail()) {
		throw FileException("File was not able to be opened.");
	} // end if
	string one, two, three;
	listLength = 0;
	while(fileIn >> one >> two >> three) {
		Col1.push_back(one);
		Col2.push_back(two);
		Col3.push_back(three);
		listLength++;
	}// end while
}// end initialize

string InsultGenerator::talkToMe() const {
	return	writeInsult(randInt(listLength),randInt(listLength),randInt(listLength));
}// end talkToMe

vector<string> InsultGenerator::generate(const int size) const {
	if (size > 10000 || size < 1) {
		throw NumInsultsOutOfBounds("The size must be between 1 and 10,000!");
	} // end if
	vector<string> insultList;
	int one, two, three, i, j, k;
	bool checkArr[listLength][listLength][listLength];
	for (i = 0; i < listLength; i++){
		for(j = 0; j < listLength; j++){
			for(k = 0; k < listLength; k++){
				checkArr[i][j][k] = false;
			}// end for
		}// end for
	}// end for
	bool check;
	for(i = 0; i < size; i++) {
		check = true;
		while (check) {
			one = randInt(listLength);
			two = randInt(listLength);
			three = randInt(listLength);
			if(!checkArr[one][two][three]){
				insultList.push_back(writeInsult(one,two,three));
				checkArr[one][two][three] = true;
				check = false;
			}// end if
		}// end while
	}// end for
	return insultList;
}// end generate

void InsultGenerator::generateAndSave(const string saveFile, const int size) const {
	if (size > 10000 || size < 1) {
		throw NumInsultsOutOfBounds("The size must be between 1 and 10,000!");
	}// end if
	ofstream fileOut(saveFile.c_str());
	if (fileOut.fail()) {
		throw FileException("File was not able to be opened.");
	}// end if
	vector<string> insultList;
	insultList = generate(size);
	int i;
	for (i = 0; i < size; i++){
		fileOut << insultList.at(i) << endl;
	}// end for
	fileOut.close();
}// end generateAndSave
