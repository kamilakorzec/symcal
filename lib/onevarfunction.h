#ifndef ONE_VAR_FUNCTION_H
#define ONE_VAR_FUNCTION_H

#include "lib/range.h"
#include "lib/onevarfunctionvalues.h"
#include "lib/nvarfunction.h"

class OneVarFunction : public NVarFunction
{
public:
    OneVarFunction() { initialized = false; }
    OneVarFunctionValues calculateValues(Range<double> range);
    OneVarFunction(vector<Token> tokens, string suffix, string standard);
    ~OneVarFunction() {}
    bool isInitialized() { return initialized; }

private:
    bool validateRange(Range<double> range);
    bool initialized;
};

#endif // ONE_VAR_FUNCTION_H
