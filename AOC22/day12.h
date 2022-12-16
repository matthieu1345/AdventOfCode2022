#pragma once
#include <string>
#include <vector>
using namespace std;


class day12
{
public:
	struct mapCoord
	{
		int x, y;
		int tDist, sDist = INT_MAX;
		int height;
		mapCoord* previous = nullptr;
		bool partOfRoute = false;

		void CalcTDist(mapCoord* finish)
		{
			tDist = abs(x - finish->x) + abs(y - finish->y);
		}

		bool CalcSDist(mapCoord* previous)
		{
			if (height <= previous->height + 1 && sDist > previous->sDist + 1)
			{
				this->previous = previous;
				sDist = previous->sDist + 1;
				return true;
			}

			return false;
		}
	};

	struct cmpMapCoords
	{
		bool operator() (const mapCoord* l, const mapCoord* r) const
		{
			return l->tDist + l->sDist > r->tDist + r->sDist;
		}
	};

	static void CreateMap();
	static void CalcTheoreticalDistances();
	static void CalcRoute();

	static string _1();
	static string _2();
	static string Run();
	static void PrintMap();
};