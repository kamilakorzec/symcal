#include "onevarfunction.h"

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
