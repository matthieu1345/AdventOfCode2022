#include "day2.h"
#include "InputReader.h"
#include <iostream>

day2::match day2::CalculateMatch(string elfChoice, string playerChoice)
{
    match output;

    output.elf = getElf(elfChoice);

    if (playerChoice == "X")
    {
        output.player = Rock;
        output.points += 1;
    }
    else if (playerChoice == "Y")
    {
        output.player = Paper;
        output.points += 2;
    }
    else if (playerChoice == "Z")
    {
        output.player = Scissor;
        output.points += 3;
    }

    if (output.player == output.elf)
    {
        output.points += 3;
    }
    else if (output.player == Rock && output.elf == Scissor
        || output.player == Paper && output.elf == Rock
        || output.player == Scissor && output.elf == Paper)
    {
        output.winner = true;
        output.points += 6;
    }

    return output;
}

day2::match day2::CalculateResult(string elfChoice, string result)
{
    string playerChoice;

    switch (getElf(elfChoice))
    {
    case Rock:
        if (result == "X") //lose scisor
        {
            playerChoice = "Z";
        }
        else if (result == "Y") //draw rock
        {
            playerChoice = "X";
        }
        else if (result == "Z") //win paper
        {
            playerChoice = "Y";
        }
        break;

    case Paper:
        if (result == "X") //lose rock
        {
            playerChoice = "X";
        }
        else if (result == "Y") //draw paper
        {
            playerChoice = "Y";
        }
        else if (result == "Z") //win scisor
        {
            playerChoice = "Z";
        }
        break;

    case Scissor:
        if (result == "X") //lose paper
        {
            playerChoice = "Y";
        }
        else if (result == "Y") //draw scissor
        {
            playerChoice = "Z";
        }
        else if (result == "Z") //win rock
        {
            playerChoice = "X";
        }
        break;
    }

    return CalculateMatch(elfChoice, playerChoice);
}

day2::RPS day2::getElf(string elfChoice)
{
    if (elfChoice == "A")
        return Rock;
    else if (elfChoice == "B")
        return Paper;
    else if (elfChoice == "C")
        return Scissor;

    return Rock;
}

string day2::day2_1()
{
    string line;
    int points = 0;

    while (fileReader->NextLine(line))
    {
        match play = day2::CalculateMatch(line.substr(0, 1), line.substr(2, 1));
        points += play.points;
        printMatch(play);
        cout << "Current Total points: " << points << endl;
    }

    return "2_1 the total points are: \033[1;96m" + to_string( points) + "\033[0m\n";
}

string day2::day2_2()
{
    string line;
    int points = 0;

    while (fileReader->NextLine(line))
    {
        match play = day2::CalculateResult(line.substr(0, 1), line.substr(2, 1));
        points += play.points;
        printMatch(play);
        cout << "Current Total points: " << points << endl;
    }

    return  "2_2 the total points are: \033[1;96m" + to_string(points) + "\033[0m\n";
}

string day2::Run()
{
    string out = "";
    fileReader = new InputReader();
    fileReader->ReadFile("day2");

    out += day2_1();

    fileReader->restart();

    out += day2_2();

    delete(fileReader);

    return out;
}

void day2::printMatch(match& input)
{
    string output = "Elf played: ";
    switch (input.elf)
    {
    case Rock:
        output += "\033[90mRock\033[0m\n";
        break;
    case Paper:
        output += "\033[33mPaper\033[0m\n";
        break;
    case Scissor: 
        output += "\033[91mScissor\033[0m\n";
        break;
    }

    output += "Player played: ";
    switch (input.player)
    {
    case Rock:
        output += "\033[90mRock\033[0m\n";
        break;
    case Paper:
        output += "\033[33mPaper\033[0m\n";
        break;
    case Scissor:
        output += "\033[91mScissor\033[0m\n";
        break;
    }

    output += "meaning you got \033[1;96m" + to_string(input.points) + "\033[0m points! \n";

    cout << output;
}
