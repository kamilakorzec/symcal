#include "lib/onevarfunctionparser.h"
#include <vector>
#include <stack>
#include <sstream>
#include <iostream>

OneVarFunction OneVarFunctionParser::fromPostfixNotation(string input)
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

                tmp.str(string());
            }
            if(!isSpace) {
                stringstream ss;
                ss << c;
                cout << c;
                Token token(ss.str(), isOperator, isVariable);
                tokens.push_back(token);
            }
        }
        else { //character
            tmp << c;
        }
    }

    stack<string> infix;
    for(vector<Token>::iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        // Push operands
        if (!it->isOperator())
        {
           infix.push(it->getValue());
        }

        else
        {
            string op1 = infix.top();
            infix.pop();
            string op2 = infix.top();
            infix.pop();
            infix.push("(" + op2 + it->getValue() + op1 + ")");
        }
    }

    OneVarFunction ovf(tokens, input, infix.top());
    return ovf;
}

OneVarFunction OneVarFunctionParser::fromInfixNotation(string input)
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

                if (!queue.empty())
                {
                    Token previous = queue.top();
                    int previousPriority = operators.getPriority(previous.getValue()[0]);

                    while(!queue.empty() && previousPriority >= newPriority)
                    {
                        cout << "P:" << previousPriority << " C:" << newPriority << endl;
                        if(c != '(' && c != ')')
                        {
                            tokens.push_back(previous);
                        }
                        queue.pop();
                    }
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
        Token token = queue.top();
        if(token.getValue()[0] != '(' && token.getValue()[0] != ')')
        {
            tokens.push_back(queue.top());
        }
        queue.pop();
    }

    for(vector<Token>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        tmp << it->getValue() << ' ';
    }

    OneVarFunction ovf(tokens, tmp.str(), input);

    return ovf;
}
