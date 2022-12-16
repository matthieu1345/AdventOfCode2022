#include "day13.h"
#include "InputReader.h"
#include <list>




day13::compare day13::CompareList(const customList &left, const customList &right)
{
    for (int i = 0; i < left.values.size(); i++)
    {
        if (right.values.size() <= i)
            return wrong;

        if (left.values[i].isList && right.values[i].isList)
        {
            compare result = CompareList(left.values[i].valueList, right.values[i].valueList);
            if (result != next)
                return result;
        }
        else if (!left.values[i].isList && !right.values[i].isList)
        {
            if (left.values[i].valueInt < right.values[i].valueInt)
                return correct;
            else if (left.values[i].valueInt > right.values[i].valueInt)
                return wrong;
        }
        else if (left.values[i].isList && !right.values[i].isList)
        {
            string newList = "[" + to_string(right.values[i].valueInt) + "]";
            compare result = CompareList(left.values[i].valueList, customList(newList));
            if (result != next)
                return result;
        }
        else if (!left.values[i].isList && right.values[i].isList)
        {
            string newList = "[" + to_string(left.values[i].valueInt) + "]";
            compare result = CompareList(newList, right.values[i].valueList);
            if (result != next)
                return result;
        }

    }

    if (left.values.size() == 0 && right.values.size() != 0)
    {
        string newList = "[]";
        compare result = CompareList(newList, right.values[0].valueList);
        if (result != next)
            return result;
    }

    if (left.values.size() == right.values.size())
        return next;

    return correct;
}

string day13::_1()
{
    string line1 ,line2;
    int counter = 0, index = 0;


    while (fileReader->NextLine(line1))
    {
        index++;
        fileReader->NextLine(line2);

        customList list1(line1), list2(line2);

        fileReader->NextLine(line1);

        if (CompareList(list1, list2) == correct)
            counter += index;
    }

    return "13_1 The sum of valid indeces is: \033[1;96m" + to_string(counter) + " \033[0m\n";
}

list<day13::customList> allLists;

string day13::_2()
{
    string line;


    while (fileReader->NextLine(line))
    {
        if (!line.empty())
            allLists.push_back(customList(line));
    }

    string temp = "[[2]]";
    customList divider1 = customList(temp);
    temp = "[[6]]";
    customList divider2 = customList(temp);
    allLists.push_back(divider1);
    allLists.push_back(divider2);

    allLists.sort();

    int index = 0;
    int output = 1;

    for (auto &current : allLists)
    {
        index++;
        if (current == divider1 || current == divider2)
            output *= index;
    }

    return "13_1 The sum of divider indeces is: \033[1;96m" + to_string(output) + " \033[0m\n";
}

string day13::Run()
{
    string output;
    fileReader = new InputReader();
    fileReader->ReadFile("day13");

    output = _1();

    fileReader->restart();

    output += _2();

    delete(fileReader);

    return output;
}

day13::customList::customList(string &input)
{
    this->input = input;
    while (input.length() > 2)
    {
        switch (input[1])
        {
        case '[':
            input.erase(input.begin());
            values.push_back(value(customList(input)));
            break;

        case ']':
            input.erase(1, 1);
            return;

        case ',':
            input.erase(1, 1);
            break;


        default:
            int lengt = input.substr(1).find_first_of("[],");
            values.push_back(value(stoi(input.substr(1, lengt))));
            input.erase(1, lengt);
            break;
        }
    }
}
