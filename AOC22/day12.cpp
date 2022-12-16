#include "day12.h"
#include "InputReader.h"
#include <queue>
#include <iostream>
using namespace std;

string height{ "abcdefghijklmnopqrstuvwxyz" };
vector<vector<day12::mapCoord*>> heightMap;
day12::mapCoord* finish, * start;

void day12::CreateMap()
{
    string line;
    heightMap.clear();
    int x = 0, y = 0;

    while (fileReader->NextLine(line))
    {
        vector<mapCoord*> currentX;

        while (!line.empty())
        {
            mapCoord* currentY = new mapCoord();
            currentY->x = x;
            currentY->y = y;
            if (line.front() == 'E')
            {
                finish = currentY;
                currentY->height = height.find('z');
            }
            else if (line.front() == 'S')
            {
                start = currentY;
                currentY->height = height.find('a');
            }
            else
                currentY->height = height.find(line.front());

            currentX.push_back(currentY);

            line.erase(line.begin());
            y++;
        }

        x++;
        y = 0;
        heightMap.push_back(currentX);
    }
}

void day12::CalcTheoreticalDistances()
{
    for (auto& line : heightMap)
    {
        for (auto coord : line)
        {
            coord->CalcTDist(finish);
        }
    }
}

priority_queue<day12::mapCoord*, vector<day12::mapCoord*>, day12::cmpMapCoords> openCoords;

void day12::CalcRoute()
{
    mapCoord* prev, *next;

    while (openCoords.top() != finish)
    {
        prev = openCoords.top();
        openCoords.pop();

        if (prev->x > 0)
        {
            next = heightMap[prev->x - 1][prev->y];
            if (next->CalcSDist(prev))
            {
                openCoords.push(next);
            }
        }

        if (prev->x < heightMap.size() - 1)
        {
            next = heightMap[prev->x + 1][prev->y];
            if (next->CalcSDist(prev))
            {
                openCoords.push(next);
            }
        }

        if (prev->y > 0)
        {
            next = heightMap[prev->x][prev->y - 1];
            if (next->CalcSDist(prev))
            {
                openCoords.push(next);
            }
        }

        if (prev->y < heightMap[prev->x].size() - 1)
        {
            next = heightMap[prev->x][prev->y + 1];
            if (next->CalcSDist(prev))
            {
                openCoords.push(next);
            }
        }
    }

    prev = openCoords.top();
    while (prev != nullptr)
    {
        prev->partOfRoute = true;
        prev = prev->previous;
    }
}

string day12::_1()
{
    CreateMap();
    CalcTheoreticalDistances();

    openCoords = priority_queue<mapCoord*, vector<mapCoord*>, cmpMapCoords>();

    start->sDist = 0;
    openCoords.push(start);

    CalcRoute();
    PrintMap();


    return "12_1 The fewest steps from start to finish are: \033[1;96m" + to_string(finish->sDist) + "\033[0m\n";
}

string day12::_2()
{
    CreateMap();
    CalcTheoreticalDistances();

    openCoords = priority_queue<mapCoord*, vector<mapCoord*>, cmpMapCoords>();
    for (auto& line : heightMap)
    {
        for (auto& coord : line)
        {
            if (coord->height == 0)
            {
                coord->sDist = 0;
                openCoords.push(coord);
            }
        }
    }

    CalcRoute();
    PrintMap();

    return "12_2 The fewest steps from start to finish are: \033[1;96m" + to_string(finish->sDist) + "\033[0m\n";
}

string day12::Run()
{
    string output;
    fileReader = new InputReader();
    fileReader->ReadFile("day12");

    output = _1();

    fileReader->restart();

    output += _2();

    delete(fileReader);

    return output;
}

void day12::PrintMap()
{
    for (auto& line : heightMap)
    {
        for (auto& coord : line)
        {
            if (coord->partOfRoute)
            {
                cout << "\033[92m";
            }
            else if (coord->previous != nullptr)
            {
                cout << "\033[91m";
            }

            cout << height[coord->height] << "\033[0m";
        }

        cout << endl;
    }
}
