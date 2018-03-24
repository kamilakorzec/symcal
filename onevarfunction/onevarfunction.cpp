#include "onevarfunction.h"
#include "inputparser/inputparser.h"

OneVarFunctionValues OneVarFunction::calculateValues(Range<float> range)
{
	return OneVarFunctionValues();
}

bool hasValue(float val) { return val > INT_MIN; }

bool OneVarFunction::validateRange(Range<float> range)
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
