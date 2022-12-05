#pragma once

#include <fstream>
using namespace std;

class InputReader
{
public:
	~InputReader();

	void ReadFile(string inputName);
	bool NextLine(string &output); // change output to be the next line, returns true if the end of the file has been reached
	void restart(); // load the last loaded file from the start

	string inputLocationChar;
	ifstream inputFile;

};

extern string inputLocation;
extern InputReader* fileReader;