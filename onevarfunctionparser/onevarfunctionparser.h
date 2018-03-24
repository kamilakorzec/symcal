#ifndef ONE_VAR_FUNCTION_PARSER_H
#define ONE_VAR_FUNCTION_PARSER_H

#include <string>
#include <onevarfunction.h>


class OneVarFunctionParser
{
public:
	OneVarFunction fromSuffixNotation(string input);
	OneVarFunction fromStandardNotation(string input);

private:
	string[] operators;
};

#endif // ONE_VAR_FUNCTION_PARSER_H
