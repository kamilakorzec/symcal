#ifndef ONE_VAR_FUNCTION_VALUES_H
#define ONE_VAR_FUNCTION_VALUES_H

#include "range/range.h"
#include "point/point.h"
#include <vector>

using namespace std;

class OneVarFunctionValues
{
public:
	vector<Point> getValues() { return values; }

private:
	Range<float> range;
	vector<Point> values;
};

#endif // ONE_VAR_FUNCTION_VALUES_H
