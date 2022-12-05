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
using namespace std;

string inputLocation = ".\\input\\";
InputReader* fileReader;

int main()
{
    day1::Run();
    day2::Run();
    day3::Run();
    return 0;
}
