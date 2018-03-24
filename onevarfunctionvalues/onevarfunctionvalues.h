#ifndef ONE_VAR_FUNCTION_VALUES_H
#define ONE_VAR_FUNCTION_VALUES_H

#include <range.h>
#include <point.h>
#include <stdlib.h>

class OneVarFunctionValues
{
public:
	vector<Point> getValues() { return values; }

private:
	Range<float> range;
	vector<Point> values;
};

#endif // ONE_VAR_FUNCTION_VALUES_H
