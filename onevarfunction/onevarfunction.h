#ifndef ONE_VAR_FUNCTION_H
#define ONE_VAR_FUNCTION_H

#include <range.h>
#include <onevarfunctionvalues.h>


class OneVarFunction:NVarFunction
{
public:
	OneVarFunctionValues calculateValues(Range<float> range);

private:
	bool validateRange(Range<float> range)
};

#endif // ONE_VAR_FUNCTION_H
