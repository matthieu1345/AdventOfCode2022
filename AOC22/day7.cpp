#include "day7.h"
#include "InputReader.h"
#include <iostream>
using namespace std;

day7::dir* currentLocation;

string day7::Day7_2()
{
	dir root;

	CreateTree(root);

	int unusedSpace = 70000000 - root.size;
	int wantedSpace = 30000000 - unusedSpace;

	cout << "starting with:\nroot size of " << root.size << endl;
	cout << "free space: 70000000 - root: " << unusedSpace << endl;
	cout << "wanted free space: 30000000" << endl;
	cout << "space to free up: 30000000 - " << unusedSpace << ": " << wantedSpace << endl;

	return "7_2 The size of the smallest cleanable directory is: \033[1;96m" + to_string( CheckSmallDir(wantedSpace, &root)) + "\033[0m\n";
}

string day7::Day7_1()
{
	dir root;

	CreateTree(root);

	PrintTree(0, &root);

	return "7_1 The sum of small directories is: \033[1;96m" + to_string(CheckChildDirs(100000, &root)) + "\033[0m\n";
}

string day7::Run()
{
	string output = "";
	fileReader = new InputReader();
	fileReader->ReadFile("day7");

	output += Day7_1();

	fileReader->restart();

	output += Day7_2();

	delete(fileReader);

	return output;
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
		{
			cout << "dir " << i->name << " is small enough to delete adding " << i->size << " to total" << endl;
			output += i->size;
		}

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
			cout << "dir " << i->name << " of size " << i->size << " is bigger than " << min << " checking delete potential of children: " << endl;
			int temp = CheckSmallDir(min, i);
			if (temp < output)
				output = temp;
		}
	}
	if (output == toCheck->size)
		cout << "dir " << toCheck->name << " has no children bigger than " << min << " to delete, nominating itself with size " << output << endl;
	else
		cout << "the smallest dir big enough in " << toCheck->name << " is of size " << output << endl;

	return output;
}

void day7::PrintTree(int depth, dir* root)
{
	for (int i = 0; i < depth; i++)
		cout << "\t";

	cout << "- " << root->name << " (dir, dirsize=" << root->size << ")" << endl;

	for (auto i : root->children)
	{
		PrintTree(depth + 1, i);
	}

	for (file &i : root->files)
	{
		for (int j = 0; j < depth + 1; j++)
			cout << "\t";
		cout << "- " << i.name << " (file, size=" << i.size << ")" << endl;
	}
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