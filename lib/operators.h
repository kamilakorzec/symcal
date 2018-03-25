#ifndef OPERATORS_H
#define OPERATORS_H

#include <map>

using namespace std;

class Operators
{
public:
    bool isOperator(char c);
    int getPriority(char c);
    Operators();

private:
    map<char, int> operatorMap;
};

#endif // OPERATORS_H
