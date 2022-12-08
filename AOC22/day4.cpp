#include "day4.h"
#include "InputReader.h"
#include <iostream>
using namespace std;

void day4::day4_shared(int &start1, int &end1, int &start2, int &end2, string line)
{
	int middle;
	string split1, split2;

	middle = line.find(",");
	split1 = line.substr(0, middle);
	split2 = line.substr(middle + 1);

	middle = split1.find("-");
	start1 = stoi(split1.substr(0, middle));
	end1 = stoi(split1.substr(middle + 1));

	middle = split2.find("-");
	start2 = stoi(split2.substr(0, middle));
	end2 = stoi(split2.substr(middle + 1));
}

string day4::day4_1()
{
	int start1, end1, start2, end2, counter = 0;
	string line;

	while (fileReader->NextLine(line))
	{
		day4_shared(start1, end1, start2, end2, line);

		if ((start1 <= start2 && end1 >= end2)
			|| (start2 <= start1 && end2 >= end1))
		{
			cout << "\033[1;91m";
			counter++;
		}

		cout << line << "\033[0m" << endl;
	}


	return "4_1 The total amount of \033[1mfully\033[0m overlapping pairs is: \033[1;96m" + to_string( counter) + "\033[m\n";
}

string day4::day4_2()
{
	int start1, end1, start2, end2, counter = 0;
	string line;

	while (fileReader->NextLine(line))
	{
		day4_shared(start1, end1, start2, end2, line);

		if ((start1 <= start2 && end1 >= start2)
			|| (start1 <= end2 && end1 >= end2)
			|| (start2 <= start1 && end2 >= start1)
			|| (start2 <= end1 && end2 >= end1))
		{
			cout << "\033[1;91m";
			counter++;
		}

		cout << line << "\033[0m" << endl;
	}

	return "4_2 The total amount of \033[1mpartial\033[0m overlapping pairs is: \033[1;96m" + to_string(counter) + "\033[0m\n";
}

string day4::Run()
{
	string output = "";
	fileReader = new InputReader();
	fileReader->ReadFile("day4");

	output += day4_1();

	fileReader->restart();

	output += day4_2();

	delete(fileReader);

	return output;
}
