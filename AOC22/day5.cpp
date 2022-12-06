#include "day5.h"
#include "InputReader.h"
#include <iostream>
#include <stack>
using namespace std;

stack<char> stacks[9];

void day5::CreateStacks()
{
/* puzzle input start

[T]             [P]     [J]
[F]     [S]     [T]     [R]     [B]
[V]     [M] [H] [S]     [F]     [R]
[Z]     [P] [Q] [B]     [S] [W] [P]
[C]     [Q] [R] [D] [Z] [N] [H] [Q]
[W] [B] [T] [F] [L] [T] [M] [F] [T]
[S] [R] [Z] [V] [G] [R] [Q] [N] [Z]
[Q] [Q] [B] [D] [J] [W] [H] [R] [J]
 1   2   3   4   5   6   7   8   9

*/
	for (int i = 0; i < 9; i++)
	{
		stacks[i].empty();
	}

	stacks[0].push('Q');
	stacks[0].push('S');
	stacks[0].push('W');
	stacks[0].push('C');
	stacks[0].push('Z');
	stacks[0].push('V');
	stacks[0].push('F');
	stacks[0].push('T');

	stacks[1].push('Q');
	stacks[1].push('R');
	stacks[1].push('B');

	stacks[2].push('B');
	stacks[2].push('Z');
	stacks[2].push('T');
	stacks[2].push('Q');
	stacks[2].push('P');
	stacks[2].push('M');
	stacks[2].push('S');

	stacks[3].push('D');
	stacks[3].push('V');
	stacks[3].push('F');
	stacks[3].push('R');
	stacks[3].push('Q');
	stacks[3].push('H');

	stacks[4].push('J');
	stacks[4].push('G');
	stacks[4].push('L');
	stacks[4].push('D');
	stacks[4].push('B');
	stacks[4].push('S');
	stacks[4].push('T');
	stacks[4].push('P');

	stacks[5].push('W');
	stacks[5].push('R');
	stacks[5].push('T');
	stacks[5].push('Z');

	stacks[6].push('H');
	stacks[6].push('Q');
	stacks[6].push('M');
	stacks[6].push('N');
	stacks[6].push('S');
	stacks[6].push('F');
	stacks[6].push('R');
	stacks[6].push('J');

	stacks[7].push('R');
	stacks[7].push('N');
	stacks[7].push('F');
	stacks[7].push('H');
	stacks[7].push('W');

	stacks[8].push('J');
	stacks[8].push('Z');
	stacks[8].push('T');
	stacks[8].push('Q');
	stacks[8].push('P');
	stacks[8].push('R');
	stacks[8].push('B');
}

void day5::day5_SplitLine(string line, int& count, int& source, int& dest)
{
	int from = line.find("from");
	int to = line.find("to");

	count = stoi(line.substr(4, from - 1));
	source = stoi(line.substr(from + 4, from - to));
	dest = stoi(line.substr(to + 2));
}

void day5::day5_1()
{
	CreateStacks();

	string line;
	int count, source, dest;

	while (fileReader->NextLine(line))

	{
		day5_SplitLine(line, count, source, dest);

		for (int c = 0; c < count; c++)
		{
			char temp = stacks[source - 1].top();
			stacks[source - 1].pop();
			stacks[dest - 1].push(temp);
		}
	}

	cout << "5_1 The top elements are: ";

	for (int i = 0; i < 9; i++)
	{
		cout << stacks[i].top() << " ";
	}

	cout << endl;
}

void day5::day5_2()
{
	CreateStacks();

	string line;
	int count, source, dest;

	while (fileReader->NextLine(line))
	{
		day5_SplitLine(line, count, source, dest);

		stack<char> temp;

		for (int c = 0; c < count; c++)
		{
			temp.push(stacks[source - 1].top());
			stacks[source - 1].pop();
		}
		for (int c = 0; c < count; c++)
		{
			stacks[dest - 1].push(temp.top());
			temp.pop();
		}
	}

	cout << "5_2 The top elements are: ";

	for (int i = 0; i < 9; i++)
	{
		cout << stacks[i].top() << " ";
	}

	cout << endl;
}

void day5::Run()
{

	fileReader = new InputReader();
	fileReader->ReadFile("day5");

	day5_1();

	fileReader->restart();

	day5_2();

	delete(fileReader);

}
