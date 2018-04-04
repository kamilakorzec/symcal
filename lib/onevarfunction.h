#ifndef ONE_VAR_FUNCTION_H
#define ONE_VAR_FUNCTION_H

#include "lib/range.h"
#include "lib/onevarfunctionvalues.h"
#include "lib/nvarfunction.h"

class OneVarFunction : NVarFunction
{
public:
    OneVarFunctionValues calculateValues(Range<double> range);
    OneVarFunction(vector<Token> tokens, string suffix, string standard);
    ~OneVarFunction() {}

private:
    bool validateRange(Range<double> range);
};

#endif // ONE_VAR_FUNCTION_H
