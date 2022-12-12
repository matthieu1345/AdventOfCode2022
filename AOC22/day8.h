#pragma once
#include <string>
#include <vector>
using namespace std;

class day8
{
public:

	struct tree
	{
		int size = 0;
		bool visible = false;
		int totalScore = 0;
		int scoreUp = 0;
		int scoreLeft = 0;
		int scoreDown = 0;
		int scoreRight = 0;

		void setVisible() { visible = true; }
		int ScenicScore() 
		{
			totalScore = scoreUp * scoreLeft * scoreDown * scoreRight;
			return totalScore;
		}

		tree(int size) : size(size) {};

		operator bool() const { return visible; }
		operator int() const { return size; }
	};


	static string Day8_2();
	static string Day8_1();
	static string Run();
	static void CalculateForest(int xSize, int ySize, std::vector<std::vector<day8::tree>>& forest);
	static int PrintForest(const vector<vector<tree>> &forest);
};

