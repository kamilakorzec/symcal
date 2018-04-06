#ifndef EXPORTER_H
#define EXPORTER_H

#include "lib/onevarfunctionvalues.h"
#include "lib/onevarfunction.h"

class Exporter
{
public:
    void exportValues(OneVarFunction *fun, OneVarFunctionValues values);
};

#endif // EXPORTER_H
