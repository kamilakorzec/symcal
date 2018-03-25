#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <map>

using namespace std;

typedef float (* funcSig)(float p1, float p2);

class Operations
{
public:
    Operations();
    funcSig getOperation(char c);

private:
    map<char, funcSig> operations;
};

#endif // OPERATIONS_H
