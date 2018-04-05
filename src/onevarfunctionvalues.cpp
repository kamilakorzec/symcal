#include "lib/onevarfunctionvalues.h"
#include "lib/operations.h"
#include <stack>
#include <sstream>
#include <iostream>

double DX = 0.01;

OneVarFunctionValues::OneVarFunctionValues(Range<double> r, vector<Token> tokens)
{
    range = r;

    Operations operations;

    for(double i = r.getFrom(); i <= r.getTo(); i += DX) {
        stack<Token> s;

        for(vector<Token>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
            if(it->isOperator())
            {
                double operand1 = stod(s.top().getValue());
                s.pop();
                double operand2 = stod(s.top().getValue());
                s.pop();

                funcSig fun = operations.getOperation(it->getValue()[0]);

                stringstream ss;
                ss << fun(operand1, operand2);

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
        cout << i << ": "<< s.top().getValue() << endl;
        values.push_back(Point(i, stod(s.top().getValue())));
    }

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
