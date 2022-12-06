#include "day6.h"
#include "InputReader.h"
#include <iostream>
#include <string>
using namespace std;

void day6::day6_1()
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
			continue;
		}

		cout << "6_1 The firs start-of-packet marker is at: " << i << " and ends at: " << i+4 << endl;
		return;
	}
}

void day6::day6_2()
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
					goto notfound;
			}
		}
		cout << "6_1 The firs start-of-message marker is at: " << i << " and ends at: " << i + 14 << endl;
		return;

	notfound:
		continue;
	}
}

void day6::Run()
{

	fileReader = new InputReader();
	fileReader->ReadFile("day6");

	day6_1();

	fileReader->restart();

	day6_2();

	delete(fileReader);

}
