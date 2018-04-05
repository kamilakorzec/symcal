#include "lib/onevarfunctionparser.h"
#include <vector>
#include <stack>
#include <sstream>
#include <iostream>

OneVarFunction OneVarFunctionParser::fromSuffixNotation(string input)
{
    stringstream tmp;
    vector<Token> tokens;

    for(unsigned int i = 0; i < input.length(); i++) {
        char c = input[i];

        bool isOperator = operators.isOperator(c);
        bool isVariable = c == 'x';
        bool isSpace = c == ' ';

        if(isOperator || isVariable || isSpace)
        {
            if(tmp.str().length() != 0)
            {
                Token t(tmp.str(), false, false);
                tokens.push_back(t);

                tmp.flush();
            }
            if(!isSpace) {
                stringstream ss;
                ss << c;

                Token token(ss.str(), isOperator, isVariable);
                tokens.push_back(token);

                if(isVariable)
                {
                    Token multiply("*", isOperator, isVariable);
                    tokens.push_back(multiply);
                }
            }
        }
        else { //character
            tmp << c;
        }
    }

    OneVarFunction ovf(tokens, input, "");
    return ovf;
}

OneVarFunction OneVarFunctionParser::fromStandardNotation(string input)
{
    stringstream tmp;
    stack<Token> queue;
    vector<Token> tokens;

    for(unsigned int i = 0; i < input.length(); i++) {
        char c = input[i];

        bool isOperator = operators.isOperator(c);
        bool isVariable = c == 'x';

        if(isOperator || isVariable)
        {
            if(tmp.str().length() != 0)
            {
                Token t(tmp.str(), false, false);
                tokens.push_back(t);

                tmp.str(string());
            }
            if(isVariable)
            {
                stringstream ss;
                ss << c;

                Token token(ss.str(), isOperator, isVariable);
                tokens.push_back(token);
            }
            else
            {
                int newPriority = operators.getPriority(c);
                stringstream ss;
                ss << c;

                Token previous;
                int previousPriority = INT_MAX;

                while(!queue.empty() && previousPriority < newPriority)
                {
                    previous = queue.top();
                    previousPriority = operators.getPriority(previous.getValue()[0]);

                    tokens.push_back(previous);
                    queue.pop();
                }

                Token t(ss.str(), isOperator, isVariable);
                queue.push(t);
            }
        }
        else { //character
            tmp << c;
        }
    }

    if(tmp.str().length())
    {
        Token t(tmp.str(), false, false);
        tokens.push_back(t);

        tmp.str(string());
    };

    while(!queue.empty())
    {
        tokens.push_back(queue.top());
        queue.pop();
    }

    for(vector<Token>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        tmp << it->getValue() << ' ';
    }

    OneVarFunction ovf(tokens, tmp.str(), input);

    return ovf;
}
