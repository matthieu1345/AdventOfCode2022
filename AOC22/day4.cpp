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

void day4::day4_1()
{
	int start1, end1, start2, end2, counter = 0;
	string line;

	while (fileReader->NextLine(line))
	{
		day4_shared(start1, end1, start2, end2, line);

		if ((start1 <= start2 && end1 >= end2)
			|| (start2 <= start1 && end2 >= end1))
		{
			counter++;
		}
	}


	cout << "4_1 The total amount of overlapping pairs is: " << counter << endl;
}

void day4::day4_2()
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
			counter++;
	}

	cout << "4_2 The total amount of overlapping pairs is: " << counter << endl;
}

void day4::Run()
{
	fileReader = new InputReader();
	fileReader->ReadFile("day4");

	day4_1();

	fileReader->restart();

	day4_2();

	delete(fileReader);

}
