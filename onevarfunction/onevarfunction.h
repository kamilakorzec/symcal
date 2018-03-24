#ifndef ONE_VAR_FUNCTION_H
#define ONE_VAR_FUNCTION_H

#include "range/range.h"
#include "onevarfunctionvalues/onevarfunctionvalues.h"
#include "nvarfunction/nvarfunction.h"


class OneVarFunction : public NVarFunction
{
public:
	OneVarFunctionValues calculateValues(Range<float> range);

private:
    bool validateRange(Range<float> range);
};

#endif // ONE_VAR_FUNCTION_H
