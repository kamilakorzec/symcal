#include "lib/onevarfunctionvalues.h"
#include "lib/operations.h"
#include <stack>
#include <sstream>

double DX = 0.01;

OneVarFunctionValues::OneVarFunctionValues(Range<double> r, vector<Token> tokens)
{
    range = r;

    Operations operations;

    for(double i = r.getFrom(); i < r.getTo() + DX; i += DX)
    {
        stack<Token> s;

        for(vector<Token>::iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            if(it->isOperator())
            {
                double operand1 = stod(s.top().getValue());
                s.pop();
                double operand2 = stod(s.top().getValue());
                s.pop();

                funcSig fun = operations.getOperation(it->getValue()[0]);

                stringstream ss;
                ss << fun(operand2, operand1);

                Token result(ss.str(), false, false);

                s.push(result);

            }
            else
            {
                Token operand = *it;
                if(it->isVariable())
                {
                    stringstream ss;
                    ss << i;
                    operand = Token(ss.str(), false, false);
                }
                s.push(operand);
            }
        }
        values.push_back(Point(i, stod(s.top().getValue())));
    }
}
