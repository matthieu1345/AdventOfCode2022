// AOC22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "InputReader.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"
#include "day10.h"
#include "day11.h"
#include "day12.h"
using namespace std;

string inputLocation = ".\\input\\";
InputReader* fileReader;

int main()
{
	string results = "";
//	results += day1::Run();
//	results += day2::Run();
//	results += day3::Run();
//	results += day4::Run();
//	results += day5::Run();
//	results += day6::Run();
//	results += day7::Run();
//	results += day8::Run();
//	results += day9::Run();
//	results += day10::Run();
//	results += day11::Run();
	results += day12::Run();
	cout << results;

	return 0;
}
