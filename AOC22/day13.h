#pragma once

#include <string>
#include <vector>
using namespace std;

class day13
{
public:
	enum compare 
	{
		wrong,
		correct,
		next
	};

	struct value;

	struct customList
	{
		customList(string& input_);
		customList() {};
		vector<value> values;
		string input = "";
		bool operator<(const customList& right)
		{
			if (CompareList(*this, right) == correct)
				return true;

			return false;
		};

		bool operator==(const customList& right)
		{
			return (input == right.input);
		};
	};

	struct value
	{
		bool isList;
		int valueInt = 0;
		customList valueList;
		value(int value) : valueInt(value) { isList = false; }
		value(customList value) : valueList(value) { isList = true; }
	};

	static compare CompareList(const customList &left, const customList &right);
	static string _1();
	static string _2();
	static string Run();
};

