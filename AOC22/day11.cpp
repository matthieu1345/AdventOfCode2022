#include "day11.h"
#include "InputReader.h"
#include <iostream>
#include <numeric>
#include <limits>
using namespace std;

void day11::RunRound(vector<monkey>& monkeys, unsigned long long lowestCommonMulti, bool useLCM)
{

	for (monkey &currentMonkey : monkeys)
	{
		while (currentMonkey.items.size() != 0)
		{
			long long currentItem = currentMonkey.items.front();

			//cout << "transformed item from " << currentItem << " to ";

			currentMonkey.items.pop();

			if (currentMonkey.multiplyOperation)
			{
				if (currentMonkey.operationNumber != 0)
				{
					currentItem *= currentMonkey.operationNumber;
				}
				else
					currentItem *= currentItem;
			}
			else
			{
				currentItem += currentMonkey.operationNumber;
			}

			if (useLCM)
				currentItem = (currentItem % lowestCommonMulti);
			else
				currentItem = (unsigned long long)floor(currentItem / 3);

			//cout << currentItem << endl;

			if (currentItem % currentMonkey.testNumber == 0)
			{
				monkeys[currentMonkey.trueMonkey].items.push(currentItem);
				//cout << "send item to " << currentMonkey.trueMonkey << endl;
			}
			else
			{
				monkeys[currentMonkey.falseMonkey].items.push(currentItem);
				//cout << "send item to " << currentMonkey.falseMonkey << endl;
			}

			currentMonkey.inspectedItems++;
		}
	}
}

vector<day11::monkey> day11::CreateMonkeys()
{
	vector<day11::monkey> output;

	string line;

	while (fileReader->NextLine(line))
	{
		// line = "Monkey #:"
		monkey _monkey;

		fileReader->NextLine(line); //  Starting items: #, #, #, #

		line = line.substr(line.find(":") + 2); //#, #, #, #

		while (line.length() >= 2)
		{
			_monkey.items.push(stoi(line.substr(0, 2)));
			if (line.length() >= 4)
				line = line.substr(4);
			else
				line = "";
		}


		fileReader->NextLine(line); //  Operation: new = old * #

		_monkey.multiplyOperation = (line[23] == '*');
		if (line.substr(25) != "old")
			_monkey.operationNumber = stoi(line.substr(25));
		else
			_monkey.operationNumber = 0;


		fileReader->NextLine(line); //  Test: divisible by #
		_monkey.testNumber = stoi(line.substr(21));


		fileReader->NextLine(line); //    If true: throw to monkey #
		_monkey.trueMonkey = stoi(line.substr(29));

		fileReader->NextLine(line); //    If false: throw to monkey #
		_monkey.falseMonkey = stoi(line.substr(30));

		fileReader->NextLine(line); // (empty)


		output.push_back(_monkey);
	}

	return output;
}

string day11::day11_1()
{
	vector<day11::monkey> monkeys = CreateMonkeys();

	for (int i = 0; i < 20; i++)
	{
		RunRound(monkeys);
	}

	unsigned long max1 = 0, max2 = 0;

	for (monkey& current : monkeys)
	{
		if (max1 > max2)
		{
			if (current.inspectedItems > max2)
			{
				max2 = current.inspectedItems;
			}
		}
		else
		{
			if (current.inspectedItems > max1)
			{
				max1 = current.inspectedItems;
			}
		}
	}


    return "11_1 The most active monkeys multiplier is: \033[1;96m" + to_string(max1 * max2) + "\033[0m\n";
}



string day11::day11_2()
{
	vector<day11::monkey> monkeys = CreateMonkeys();

	unsigned long long lowestCommonMultiplier = 1;
	for (int i = 0; i < monkeys.size(); i++)
		lowestCommonMultiplier *= monkeys[i].testNumber;

	for (int i = 0; i < 10000; i++)
	{
		RunRound(monkeys, lowestCommonMultiplier, true);

		cout << "\033[1;96m we run " << i << " rounds\033[0m" << endl;
	}

	unsigned long long max1 = 0, max2 = 0;

	for (monkey& current : monkeys)
	{
		if (max1 > max2)
		{
			if (current.inspectedItems > max2)
			{
				max2 = current.inspectedItems;
			}
		}
		else
		{
			if (current.inspectedItems > max1)
			{
				max1 = current.inspectedItems;
			}
		}
	}

	return "11_2 The most active monkeys multiplier is: \033[1;96m" + to_string(max1 * max2) + "\033[0m\n";
}

string day11::Run()
{
	string output = "";

	fileReader = new InputReader();
	fileReader->ReadFile("day11");

	output = day11_1();

	fileReader->restart();

	output += day11_2();

	delete(fileReader);

	return output;
}