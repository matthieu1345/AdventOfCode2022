#include "InputReader.h"
#include <iostream>
#include <string>
using namespace std;

/*
	fileReader = new InputReader();
	fileReader->ReadFile("day1");

	output = day1_1();

	fileReader->restart();

	output += day1_2();

	delete(fileReader);
*/

InputReader::~InputReader()
{
	inputFile.close();
}

void InputReader::ReadFile(string inputFileName)
{
	inputLocationChar = inputLocation + inputFileName;
	
	inputFile.open(inputLocationChar);
}

bool InputReader::NextLine(string& output)
{
	bool ended = !inputFile.eof();

	getline(inputFile, output);

	if (inputFile.eof() && output.length() == 0)
		ended = false;

	return ended;
}
	
void InputReader::restart() 
{
	inputFile.close();
	inputFile.open(inputLocationChar);
}