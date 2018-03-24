#include "onevarfunction.h"

OneVarFunctionValues OneVarFunction::calculateValues(Range<float> range)
{
	return OneVarFunctionValues();
}

bool OneVarFunction::validateRange(Range<float> range)
{
	bool hasValue(float val) { return val > INT_MIN };
	float from = range.getFrom();
	float to = range.getTo();

	return  hasValue(from) && hasValue(to) && from < to;
}
