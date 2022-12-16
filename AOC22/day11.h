#pragma once
#include <string>
#include <queue>
#include <vector>
using namespace std;

class day11
{
public:
	struct monkey
	{
	public:
		int inspectedItems = 0;
		queue<long long> items;
		bool multiplyOperation;
		int operationNumber;
		int testNumber;
		int trueMonkey, falseMonkey;
	};

	static void RunRound(vector<monkey>& monkeys, unsigned long long lowestCommonMulti = 3, bool useLCM = false);
	static vector<monkey> CreateMonkeys();
	static string day11_1();
	static string day11_2();
	static string Run();
};

