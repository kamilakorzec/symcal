#include "lib/onevarfunction.h"
#include "lib/inputparser.h"
#include <stdexcept>

OneVarFunctionValues OneVarFunction::calculateValues(Range<double> range)
{
    bool validRange = validateRange(range);
    OneVarFunctionValues vals(range, representation);
    if(!validRange)
    {
        throw invalid_argument("invalid range");
        return vals;
    }
    else
    {

        return vals;
    }
}

bool hasValue(float val) { return val > INT_MIN; }

bool OneVarFunction::validateRange(Range<double> range)
{
	float from = range.getFrom();
	float to = range.getTo();

	return  hasValue(from) && hasValue(to) && from < to;
}

OneVarFunction::OneVarFunction(vector<Token> tokens, string suffix = "", string standard = "")
{
    suffixNotation = suffix;
    standardNotation = standard;
    representation = tokens;
    initialized = true;
}
