#include "day1.h"

#include <iostream>
#include "InputReader.h"
using namespace std;

void day1::day1_Shared(list<int>& maxCal)
{
    maxCal.sort(greater<int>());
    string line;
    int currentCal = 0;
    int i = 0;

    while (fileReader->NextLine(line))
    {
        if (line.length() == 0)
        {
            cout << "elf " << i << " summed callory count is: " << currentCal << endl;
            if (currentCal > maxCal.front())
            {
                maxCal.push_front(currentCal);
                maxCal.pop_back();
            }


            cout << "current ranking: " << endl;
            for (auto j : maxCal)
            {
                cout << j << endl;
            }

            currentCal = 0;
            i++;
            cout << "elf number " << i << endl;

        }
        else
        {
            cout << line << endl;
            currentCal += stoi(line);
        }
    }
}

string day1::day1_1()
{
    list<int> output(1, 0);
    day1_Shared(output);

    string out = "1_1 The highest callory count is: \033[1;96m";
    out += to_string(output.front());
    out += "\033[0m\n";
    return out;
}

string day1::day1_2()
{
    list<int> output(3, 0);
    day1_Shared(output);

    int total = 0;

    string out = "1_2 The highest callory counts are: ";
    for (int i : output)
    {
        total += i;
        out += to_string(i);
        out += ", ";
    }
    out += "\t\tfor a total of: \033[1;96m";
    out += to_string(total);
    out += "\033[0m\n";

    return out;
}

string day1::Run()
{
    string output;
    fileReader = new InputReader();
    fileReader->ReadFile("day1");

    output = day1_1();

    fileReader->restart();

    output += day1_2();

    delete(fileReader);

    return output;
}