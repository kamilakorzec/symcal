#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <map>

using namespace std;

// define a single type to return operations as
typedef float (* funcSig)(double p1, double p2);

/*
 * Operations class.
 * Contains all available operations to perform on operands
 * as well as their operators
 */
class Operations
{
public:
    Operations();
    funcSig getOperation(char c);

private:
    map<char, funcSig> operations;
};

#endif // OPERATIONS_H
