#pragma once
#include <string>
#include <vector>
using namespace std;

class day10
{
public: 

	static string day10_1();
	static string day10_2();
	static void CheckCycle(int& pixel, int reg, vector<bool>& outputVector, int& counter);
	static string Run();
};

