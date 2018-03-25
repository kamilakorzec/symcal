#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <map>

using namespace std;

typedef float (* funcSig)(float p1, float p2);

class Operations
{
public:
    Operations();
    funcSig getOperation();

private:
    map<char, funcSig> ops;
};

#endif // OPERATIONS_H
