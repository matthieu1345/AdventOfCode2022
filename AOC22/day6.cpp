#include "day6.h"
#include "InputReader.h"
#include <iostream>
using namespace std;

string day6::day6_1()
{
	string line;
	fileReader->NextLine(line);

	for (int i = 0; i + 3 <= line.length(); i++)
	{
		string sub = line.substr(i, 4);
		if (sub[0] == sub[1] || sub[0] == sub[2] || sub[0] == sub[3]
			|| sub[1] == sub[2] || sub[1] == sub[3]
			|| sub[2] == sub[3])
		{
			cout << sub[0] << " is duplicated in " << sub << endl;
			continue;
		}

		return "6_1 The firs start-of-packet marker is at: \033[1;96m" + to_string(i) + "\033[0m and ends at: \033[1;96m" + to_string( i+4) + "\033[0m\n";
	}
	return "6_1 Failed";
}

string day6::day6_2()
{
	string line;
	fileReader->NextLine(line);

	for (int i = 0; i + 13 <= line.length(); i++)
	{
		string sub = line.substr(i, 14);
		for (int j = 0; j <= sub.length() - 1; j++)
		{
			for (int k = j + 1; k <= sub.length(); k++)
			{
				if (sub[j] == sub[k])
				{
					cout << sub[j] << " is duplicated in " << sub << endl;
					goto notfound;
				}
			}
		}
		return "6_2 The firs start-of-message marker is at: \033[1;96m" + to_string(i) + "\033[0m and ends at: \033[1;96m" + to_string(i + 14) + "\033[0m\n";
	notfound:
		continue;
	}

	return "6_2 Failed";
}

string day6::Run()
{
	string output = "";
	fileReader = new InputReader();
	fileReader->ReadFile("day6");

	output += day6_1();

	fileReader->restart();

	output += day6_2();

	delete(fileReader);

	return output;
}
