#include "day3.h"
#include "InputReader.h"
#include <iostream>
#include <map>
using namespace std;

map<char, int> letterScore;

string day3::Run()
{
    string output = "";

    initPointmap();
    fileReader = new InputReader();
    fileReader->ReadFile("day3");

    output += day3_1();

    fileReader->restart();

    output += day3_2();

    delete(fileReader);

    return output;
}

void day3::initPointmap()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int counter = 1;

    for (char i : alphabet)
    {
        letterScore[i] = counter;
        counter++;
    }
}

string day3::day3_1()
{
    string line, comp1, comp2;
    int points = 0;


    while (fileReader->NextLine(line))
    {
        if (line.length() == 0)
        {

        }
        else
        {
            comp1 = line.substr(0, (line.length() / 2));
            comp2 = line.substr((line.length() / 2));

            cout << "Comparing rucksacks compartments: " << comp1 << " : " << comp2 << endl;

            for (auto i : comp1)
            {
                if (comp2.find(i) != string::npos)
                {
                    cout << "Duplicate letter " << i << " found, adding prio " << to_string(letterScore[i]) << endl;
                    points += letterScore[i];
                    cout << "Current total: " << to_string(points) << endl;
                    break;
                }
            }
        }
    }

    return "3_1 The prioritys sum is: \033[1;96m" + to_string(points) + "\033[0m\n";
}

string day3::day3_2()
{
    string line1, line2, line3;
    int points = 0;


    while (fileReader->NextLine(line1))
    {
        fileReader->NextLine(line2);
        fileReader->NextLine(line3);
        if (line1.length() == 0)
        {

        }
        else
        {
            cout << "Comparing rucksacks: " << line1 << " : " << line2 << " : " << line3 << endl;
            for (auto i : line1)
            {
                if (line2.find(i) != string::npos && line3.find(i) != string::npos)
                {
                    cout << "Tripple duplicate letter " << i << " found, adding prio " << to_string(letterScore[i]) << endl;
                    points += letterScore[i];
                    cout << "Current total: " << to_string(points) << endl;
                    break;
                }
            }
        }
    }

    return "3_2 The prioritys sum is: \033[1;96m" + to_string(points) + "\033[0m\n";
}