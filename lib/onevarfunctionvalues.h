#ifndef ONE_VAR_FUNCTION_VALUES_H
#define ONE_VAR_FUNCTION_VALUES_H

#include "lib/range.h"
#include "lib/point.h"
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
