#ifndef ONE_VAR_FUNCTION_PARSER_H
#define ONE_VAR_FUNCTION_PARSER_H

#include <string>
#include "lib/onevarfunction.h"
#include "lib/operators.h"

using namespace std;

/*
 * OneVarFunctionParser class
 * Contains two main methods parsing input string and
 * returning OneVarFunction class instance.
 */
class OneVarFunctionParser
{
public:
    OneVarFunction fromPostfixNotation(string input);
    OneVarFunction fromInfixNotation(string input);

private:
    Operators operators;
};

#endif // ONE_VAR_FUNCTION_PARSER_H
