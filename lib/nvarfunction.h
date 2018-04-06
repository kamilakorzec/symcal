#ifndef N_VAR_FUNCTION_H
#define N_VAR_FUNCTION_H

#include "lib/token.h"
#include <vector>
#include <string>

using namespace std;

/*
 * Parent class
 * Represents function with n used variables
 * Contains its representation in form of vector of tokens,
 * and two strings representing postfix and infix notation.
 */
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
