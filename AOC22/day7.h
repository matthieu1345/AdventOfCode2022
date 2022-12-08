#pragma once
#include <list>
#include <string>
using namespace std;

class day7
{
public:
	struct file
	{
		int size;
		string name;

		file(int size, string name) : size(size), name(name) {};
	};

	struct dir
	{
		string name;
		dir* parent = nullptr;
		list<dir*> children;
		list<file> files;

		int size = 0;

		dir() {};
		dir(string name, dir* parent);
		~dir();

		void addDir(string name) { children.push_back(new dir(name, this)); };
		void addFile(int size, string name);
		void addSize(int size);
		
		void openChild(string name);
	};



	static string Day7_2();
	static string Day7_1();
	static string Run();

	static void RunCommand(string command);
	static void CreateTree(dir& root);
	static int CheckChildDirs(int max, dir* toCheck);
	static int CheckSmallDir(int min, dir* toCheck);
	static void PrintTree(int depth, dir* root);
};

