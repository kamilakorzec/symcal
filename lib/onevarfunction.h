#ifndef ONE_VAR_FUNCTION_H
#define ONE_VAR_FUNCTION_H

#include "lib/range.h"
#include "lib/onevarfunctionvalues.h"
#include "lib/nvarfunction.h"


class OneVarFunction : NVarFunction
{
public:
    OneVarFunctionValues calculateValues(Range<float> range);
    OneVarFunction(string suffix, string standard);
    ~OneVarFunction() {}

private:
    bool validateRange(Range<float> range);
};

#endif // ONE_VAR_FUNCTION_H
