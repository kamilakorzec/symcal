#include "lib/onevarfunctionparser.h"

OneVarFunction OneVarFunctionParser::fromSuffixNotation(string input)
{
    OneVarFunction ovf(input, "");
    return ovf;
}

OneVarFunction OneVarFunctionParser::fromStandardNotation(string input)
{

    for(int i = 0; i < input.length(); i++) {
        if(input[i] != ' ') {
            if(operators.isOperator(input[i])) {

            }
            else { //character

            }
        }
    }

    OneVarFunction ovf("", input);

    return ovf;
}
