#include "day8.h"
#include "InputReader.h"
#include <iostream>
using namespace std;

string day8::Day8_2()
{
	string line = "";

	vector<vector<tree>> forest;

	int xSize = 0;

	while (fileReader->NextLine(line))
	{
		vector<tree> row;
		for (int i = 0; i < line.length(); i++)
		{
			row.push_back(tree(int(line[i] - '0')));
		}

		forest.push_back(row);
		xSize++;
	}
	int ySize = (int)line.length();

	CalculateForest(xSize, ySize, forest);

	tree max = forest[0][0];

	for (vector<tree> &row : forest)
	{
		for (tree &current : row)
		{
			if (current.ScenicScore() > max.ScenicScore())
			{
				cout << "new max scenic score of: " << current.ScenicScore() << endl;
				max = current;
			}
		}
	}

	return "8_2 The highest scenic score tree is: \033[1;96m" + to_string(max.ScenicScore()) + "\033[0m\n";
}

string day8::Day8_1()
{
	string line = "";

	vector<vector<tree>> forest;

	int xSize = 0;

	while (fileReader->NextLine(line))
	{
		vector<tree> row;
		for (int i = 0; i < line.length(); i++)
		{
			row.push_back(tree(int( line[i] - '0')));
		}

		forest.push_back(row);
		xSize++;
	}
	int ySize = (int)line.length();

	CalculateForest(xSize, ySize, forest);

	int visible = PrintForest(forest);

	return "8_1 The amount of visible trees is: \033[1;96m" + to_string(visible) + "\033[0m\n";
}

string day8::Run()
{
	string output = "";
	fileReader = new InputReader();
	fileReader->ReadFile("day8");

	output += Day8_1();

	fileReader->restart();

	output += Day8_2();

	delete(fileReader);

	return output;
}

void day8::CalculateForest(int xSize, int ySize, std::vector<std::vector<day8::tree>>& forest)
{
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			bool test = true;
			for (int _x = x; _x >= 0; _x--)
			{
				if (x != _x)
					forest[x][y].scoreUp++;
				if (x != _x && forest[_x][y].size >= forest[x][y].size)
				{
					cout << "Tree " << x << "," << y << " cant be seen from the top because " << _x << "," << y << " is higher." << endl;
					test = false;
					break;
				}

			}

			if (test)
				forest[x][y].setVisible();

			test = true;

			for (int _x = x + 1; _x < xSize; _x++)
			{
				if (x != _x)
					forest[x][y].scoreDown++;
				if (x != _x && forest[_x][y].size >= forest[x][y].size)
				{
					cout << "Tree " << x << "," << y << " cant be seen from the bottom because " << _x << "," << y << " is higher." << endl;
					test = false;
					break;
				}
			}

			if (test)
				forest[x][y].setVisible();

			test = true;

			for (int _y = y; _y >= 0; _y--)
			{
				if (y != _y)
					forest[x][y].scoreLeft++;
				if (y != _y && forest[x][_y].size >= forest[x][y].size)
				{
					cout << "Tree " << x << "," << y << " cant be seen from the left because " << x << "," << _y << " is higher." << endl;
					test = false;
					break;
				}
			}

			if (test)
				forest[x][y].setVisible();

			test = true;

			for (int _y = y; _y < ySize; _y++)
			{
				if (y != _y)
					forest[x][y].scoreRight++;
				if (y != _y && forest[x][_y].size >= forest[x][y].size)
				{
					cout << "Tree " << x << "," << y << " cant be seen from the right because " << x << "," << _y << " is higher." << endl;
					test = false;
					break;
				}
			}

			if (test)
				forest[x][y].setVisible();

			cout << "Tree " << x << "," << y << " can " << (!forest[x][y] ? "not " : "") << "be seen." << endl;
		}
	}
}

int day8::PrintForest(const vector<vector<tree>>& forest)
{
	int output = 0;
	for (vector<tree> row : forest)
	{
		for (tree _tree : row)
		{
			string map = "";
			if (!_tree)
			{
				map += "\033[91m";
			}
			else
				output++;
			map += to_string(_tree.size);
			if (!_tree)
			{
				map += "\033[0m";
			}
			cout << map;
		}
		cout << endl;
	}

	return output;
}
