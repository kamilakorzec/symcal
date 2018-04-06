#include "lib/operations.h"
#include <math.h>

float multiply(double x, double y) { return x * y; }
float add(double x, double y) { return x + y; }
float subtract(double x, double y) { return x - y; }
float divide(double x, double y) { return x / y; }
float power(double x, double y) { return pow(x, y); }
float noop(double x, double y) { return (double) INT_MAX; }

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

funcSig Operations::getOperation(char c)
{
    return operations.at(c);
}
