#include "lib/onevarfunctionvalues.h"

OneVarFunctionValues::OneVarFunctionValues(Range<double> r)
{
    range = r;

    // for each token in the postfix expression:
    // if token is an operator:
    //     operand_2 ← pop from the stack
    //     operand_1 ← pop from the stack
    //     result ← evaluate token with operand_1 and operand_2
    //     push result back onto the stack
    // else if token is an operand:
    //     push token onto the stack
    // result ← pop from the stack

    // Source:
    // https://en.wikipedia.org/wiki/Reverse_Polish_notation#Implementations
}
