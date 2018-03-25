#ifndef ONE_VAR_FUNCTION_PARSER_H
#define ONE_VAR_FUNCTION_PARSER_H

#include <string>
#include "lib/onevarfunction.h"
#include "lib/operators.h"

using namespace std;

class OneVarFunctionParser
{
public:
	OneVarFunction fromSuffixNotation(string input);
	OneVarFunction fromStandardNotation(string input);

private:
    Operators operators;
};

#endif // ONE_VAR_FUNCTION_PARSER_H
