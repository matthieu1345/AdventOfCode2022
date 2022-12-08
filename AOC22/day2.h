#pragma once

#include <fstream>
#include <string>
using namespace std;

class day2
{
public:
	enum RPS
	{
		Rock,
		Paper,
		Scissor
	};

	struct match
	{
		RPS elf = Rock;
		RPS player = Rock;
		bool winner = false;
		int points = 0;
	};

	static match CalculateMatch(string elfChoice, string playerChoice);
	static match CalculateResult(string elfChoice, string result);
	static RPS getElf(string choice);

	static string day2_1();

	static string day2_2();

	static string Run();

	static void printMatch(match& input);


};

