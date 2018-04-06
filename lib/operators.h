#ifndef OPERATORS_H
#define OPERATORS_H

#include <map>

using namespace std;

/*
 * Operators class
 * Contains map character -> operator
 */
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
