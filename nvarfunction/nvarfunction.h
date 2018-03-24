#ifndef N_VAR_FUNCTION_H
#define N_VAR_FUNCTION_H

#include <string>


class NVarFunction
{
public:
	string toSuffixNotation();
	string toStandardNotation();
	~NVarFunction;

protected:
	string[] representation;
	string suffixNotation;
	string standardNotation;
};

#endif // N_VAR_FUNCTION_H
