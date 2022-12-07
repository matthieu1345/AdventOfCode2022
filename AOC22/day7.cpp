#include "day7.h"
#include "InputReader.h"
#include <iostream>
using namespace std;

day7::dir* currentLocation;

void day7::Day7_2()
{
	dir root;

	CreateTree(root);

	int unusedSpace = 70000000 - root.size;
	int wantedSpace = 30000000 - unusedSpace;

	int unusedSpaceTest = 70000000 - 48381165;
	int wantedSpaceTest = 30000000 - unusedSpaceTest;

	cout << "7_2 The size of the smallest cleanable directory is: " << CheckSmallDir(wantedSpace, &root) << endl;
}

void day7::Day7_1()
{
	dir root;

	CreateTree(root);

	cout << "7_1 The sum of small directories is: " << CheckChildDirs(100000, &root) << endl;
}

void day7::Run()
{
	fileReader = new InputReader();
	fileReader->ReadFile("day7");

	Day7_1();

	fileReader->restart();

	Day7_2();

	delete(fileReader);

}

void day7::RunCommand(string line)
{
	if (line.substr(0, 2) == "cd")
	{
		if (line.substr(3, 2) == "..")
			currentLocation = currentLocation->parent;
		else
			currentLocation->openChild(line.substr(3));
	}
	else if (line.substr(0, 2) == "ls")
	{

	}
}

void day7::CreateTree(dir& root)
{
	string line;
	root = dir("/", nullptr);
	currentLocation = &root;
	fileReader->NextLine(line);

	while (fileReader->NextLine(line))
	{
		if (line[0] == '$')
			RunCommand(line.substr(2));
		else if (line.substr(0, 3) == "dir")
		{
			currentLocation->addDir(line.substr(4));
		}
		else
		{
			int space = line.find(" ");
			currentLocation->addFile(stoi(line.substr(0, space)), line.substr(space + 1));
		}
	}
}

int day7::CheckChildDirs(int max, dir* toCheck)
{
	int output = 0;
	for (auto i : toCheck->children)
	{
		if (i->size <= max)
			output += i->size;

		output += CheckChildDirs(max, i);
	}

	return output;
}

int day7::CheckSmallDir(int min, dir* toCheck)
{
	int output = toCheck->size;

	for (auto i : toCheck->children)
	{
		if (i->size >= min)
		{
			int temp = CheckSmallDir(min, i);
			if (temp < output)
				output = temp;
		}
			
	}

	return output;
}

day7::dir::dir(string name, dir* parent)
{
	this->name = name;
	this->parent = parent;
}

day7::dir::~dir()
{
	for (auto i : children)
		delete(i);
}

void day7::dir::addFile(int size, string name)
{
	files.push_back(file(size, name));
	addSize(size);
}

void day7::dir::addSize(int size)
{
	this->size += size;

	if (parent != nullptr)
	{
		parent->addSize(size);
	}
}

void day7::dir::openChild(string name)
{
	for (auto i : children)
	{
		if (i->name == name)
			currentLocation = i;
	}

	addDir(name);
	currentLocation = children.back();
}