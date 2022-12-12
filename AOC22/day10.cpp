#include "day10.h"
#include "InputReader.h"
#include <iostream>
#include <vector>
using namespace std;

string day10::day10_1()
{
	string line;
	int output = 0, reg = 1, counter = 0, lastOutput = -20;

	while (fileReader->NextLine(line))
	{
		counter++;

		if (counter - lastOutput > 39)
		{
			lastOutput = ((counter / 40) * 40) + 20;
			output += (reg * counter);
			cout << "The register's value at " << counter << " has a value of " << reg << " giving a total strength of " << output << endl;
		}

		if (line.substr(0, 4) == "addx")
		{
			counter++;

			if (counter - lastOutput > 39)
			{
				lastOutput = ((counter / 40) * 40) + 20;
				output += (reg * counter);
				cout << "The register's value at cycle " << counter << " has a value of " << reg << " giving a total strength of " << output << endl;
			}

			reg += stoi(line.substr(5));
		}



	}



	return "10_1 The final summed strength is: \033[1;96m" + to_string(output) + "\033[0m\n";
}

string day10::day10_2()
{
	string line;
	int reg = 1, counter = 1 , pixel = 0;
	vector<bool> outputVector;

	while (fileReader->NextLine(line))
	{
		CheckCycle(pixel, reg, outputVector, counter);

		if (line.substr(0, 4) == "addx")
		{
			CheckCycle(pixel, reg, outputVector, counter);
			reg += stoi(line.substr(5));
		}

	}

	string output = "10_2:\n";

	for (int i = 0; i < outputVector.size(); i++)
	{
		output += outputVector[i] ? "\033[1;96m#\033[0m" : ".";
		if (i % 40 == 39)
			output += "\n";
	}

	return output;
}

void day10::CheckCycle(int& pixel, int reg, std::vector<bool>& outputVector, int& counter)
{
	if (abs(pixel - reg) <= 1)
		outputVector.push_back(true);
	else
		outputVector.push_back(false);

	cout << "cycle " << counter << " reg " << reg << " making the pixel " << (outputVector.back() ? "lit" : "dark") << endl;

	counter++;
	pixel++;
	if (pixel >= 40)
		pixel -= 40;
}

string day10::Run()
{
	string output = "";

	fileReader = new InputReader();
	fileReader->ReadFile("day10");

	output = day10_1();

	fileReader->restart();

	output += day10_2();

	delete(fileReader);

	return output;
}
