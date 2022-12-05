#include "day1.h"

#include <string>
#include <iostream>
#include "InputReader.h"
using namespace std;

void day1::day1_Shared(list<int>& maxCal)
{
    maxCal.sort(greater<int>());
    string line;
    int currentCal = 0;

    while (fileReader->NextLine(line))
    {
        if (line.length() == 0)
        {
            if (currentCal > maxCal.front())
            {
                maxCal.push_front(currentCal);
                maxCal.pop_back();
            }
            currentCal = 0;
        }
        else
        {
            currentCal += stoi(line);
        }
    }
}

void day1::day1_1()
{
    list<int> output(1, 0);
    day1_Shared(output);

    cout << "1_1 The highest callory count is: " << output.front() << endl;
}

void day1::day1_2()
{
    list<int> output(3, 0);
    day1_Shared(output);

    int total = 0;

    cout << "1_2 The highest callory counts are: " << endl;
    for (int i : output)
    {
        total += i;
        cout << i << ", ";
    }
    cout << endl << "for a total of: " << total << endl;
}

void day1::Run()
{
    fileReader = new InputReader();
    fileReader->ReadFile("day1");

    day1_1();

    fileReader->restart();

    day1_2();

    delete(fileReader);
}