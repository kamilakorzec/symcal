#include "lib/operators.h"

int Operators::getPriority(char c)
{
    return operatorMap.at(c);
}

bool Operators::isOperator(char c)
{
    return operatorMap.find(c) != operatorMap.end();
}

Operators::Operators()
{
    //TODO: move keys to a set common with Operations, maybe?
    map<char, int> om = {
        {'(', 0},
        {'+', 1},
        {'-', 1},
        {')', 1},
        {'*', 2},
        {'/', 2},
        {'%', 2},
        {'^', 3}
    };

    operatorMap = om;
}
