#ifndef N_VAR_FUNCTION_H
#define N_VAR_FUNCTION_H

#include "lib/token.h"
#include <vector>
#include <string>

using namespace std;

class NVarFunction
{
public:
    string toPostfixNotation() { return suffixNotation; }
    string toInfixNotation() { return standardNotation; }
    ~NVarFunction() {}

protected:
    vector<Token> representation;
	string suffixNotation;
	string standardNotation;
};

#endif // N_VAR_FUNCTION_H
