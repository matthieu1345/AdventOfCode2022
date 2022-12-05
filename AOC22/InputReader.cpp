#include "InputReader.h"
#include <iostream>
#include <string>
using namespace std;

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
	return ended;
}
	
void InputReader::restart() 
{
	inputFile.close();
	inputFile.open(inputLocationChar);
}