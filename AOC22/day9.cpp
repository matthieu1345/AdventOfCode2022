#include "day9.h"
#include "InputReader.h"
#include <set>
#include <tuple>
using namespace std;

void day9::CalcTail(int head[2], int tail[2])
{
	int dist[2];
	dist[0] = tail[0] - head[0];
	dist[1] = tail[1] - head[1];

	if (abs(dist[0]) < 2 &&  abs(dist[1]) < 2)
		return;

	if (dist[0] > 0)
	{
		tail[0]--;
	}
	if (dist[0] < 0)
	{
		tail[0]++;
	}
	if (dist[1] > 0)
	{
		tail[1]--;
	}
	if (dist[1] < 0)
	{
		tail[1]++;
	}
}

string day9::day9_2()
{
	int head[2] = { 0,0 }, tail[9][2] = { 0,0 };

	set<pair<int, int>> visitedCoords;

	string line;
	while (fileReader->NextLine(line))
	{
		for (int i = stoi(line.substr(2)); i > 0; i--)
		{
			switch (line[0])
			{
			case 'U':
				head[0]++;
				break;

			case 'L':
				head[1]--;
				break;

			case 'R':
				head[1]++;
				break;

			case 'D':
				head[0]--;
				break;
			}

			CalcTail(head, tail[0]);

			for (int i = 1; i < 9; i++)
				CalcTail(tail[i-1], tail[i]);

			visitedCoords.insert(pair<int, int>(tail[8][0], tail[8][1]));
		}
	}

	return  "9_2 The amount of tail[8] visited places is: \033[1;96m" + to_string(visitedCoords.size()) + "\033[0m\n";
}

string day9::day9_1()
{
	int head[2] = { 0,0 }, tail[2] = { 0,0 };

	set<pair<int,int>> visitedCoords;

	string line;
	while (fileReader->NextLine(line))
	{
		for (int i = stoi(line.substr(2)); i > 0; i--)
		{
			switch (line[0])
			{
			case 'U':
				head[0]++;
				break;

			case 'L':
				head[1]--;
				break;

			case 'R':
				head[1]++;
				break;

			case 'D':
				head[0]--;
				break;
			}

			CalcTail(head, tail);
			visitedCoords.insert(pair<int, int>(tail[0], tail[1]));
		}
	}

	return  "9_1 The amount of tail visited places is: \033[1;96m" + to_string(visitedCoords.size()) + "\033[0m\n";
}

string day9::Run()
{
	string output = "";

	fileReader = new InputReader();
	fileReader->ReadFile("day9");

	output = day9_1();

	fileReader->restart();

	output += day9_2();

	delete(fileReader);

	return output;
}
