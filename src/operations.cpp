#include "operations.h"
#include <math.h>

float multiply(float x, float y) { return x * y; }
float add(float x, float y) { return x + y; }
float subtract(float x, float y) { return x - y; }
float divide(float x, float y) { return x / y; }
float power(float x, float y) { return pow(x, y); }
float noop(float x, float y) { return (float) INT_MAX; }

Operations::Operations()
{
    map<char, funcSig> ops = {
        {'(', noop},
        {'+', add},
        {'-', subtract},
        {')', noop},
        {'*', multiply},
        {'/', divide},
        {'^', power}
    };

    operations = ops;
}

funcSig Operations::getOperation(char c) {
    return operations.at(c);
}
