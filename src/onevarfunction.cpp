#include "lib/onevarfunction.h"
#include "lib/inputparser.h"
#include <stdexcept>

OneVarFunctionValues* OneVarFunction::calculateValues(Range<double> range)
{
    bool validRange = validateRange(range);
    OneVarFunctionValues* vals = new OneVarFunctionValues(range);
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

OneVarFunction::OneVarFunction(string suffix = "", string standard = "")
{
    if(suffix.length() != 0)
    {
        suffixNotation = suffix;
    }

    if(standard.length() != 0)
    {
        standardNotation = standard;
    }
}
