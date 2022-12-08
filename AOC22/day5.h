#pragma once
#include <string>
using namespace std;

class day5
{
public: 
	static void CreateStacks();
	static void day5_SplitLine(string line, int &count, int &source, int &dest);
	static string day5_1();
	static string day5_2();
	static string Run();
};

