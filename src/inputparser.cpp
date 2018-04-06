#include "lib/inputparser.h"
#include "lib/operators.h"
#include <stdexcept>
#include <algorithm>
#include <ctype.h>

string InputParser::copyString(string input) {
    char* str = new char[input.size() + 1];
    copy(input.begin(), input.end(), str);
    str[input.size()] = '\0';

    return string(str);
}

string InputParser::removeSpaces(string str) {
   str.erase(remove_if(str.begin(), str.end(), [](char c)
   {
       return std::isspace(static_cast<unsigned char>(c));
   }), str.end());

   return str;
}

string InputParser::parseInfix(string input)
{
    string str = removeSpaces(sanitize(input));
    bool isValid = validateInfix(str);

    if(isValid)
    {
        return str;
    }
    else
    {
        throw invalid_argument("Invalid input: " + str);
        return "";
    }
}

string InputParser::sanitize(string input)
{
    string str = copyString(input);

    return removeSpaces(str);
}

bool InputParser::validateInfix(string input)
{
    int subsequentOperators = 0;
    int openedBrackets = 0;
    Operators o;

    for(unsigned int i=0; i < input.length(); i++) {
        char c = input[i];

        if(!isdigit(c) && c != 'x') { //ignore all digits
            if(isalpha(c))
            {
                return false;
            }
            else if(c != 'x')
            {   //it can't be digit, space or x - it must be an operator
                //there can be only one subsequent operator (different than bracket)
                if(c == '(')
                {
                    subsequentOperators++;
                    openedBrackets++;
                }
                else if(c == ')')
                {
                    if(openedBrackets < 1) return false;
                    openedBrackets--;
                }
                else
                {
                    if(subsequentOperators) return false; //there can't be two operators next to each other
                    if(!o.isOperator(c)) return false; //no symbols other than operators are accepted
                    subsequentOperators++;
                }
            }
        }
        else {
            if(subsequentOperators)
            {
                subsequentOperators = 0;
            }
            if(c == 'x')
            {
                if(input[i-1] == c)
                {
                    return false;
                }
            }
        }
    }

    char last = input[input.length() - 1];
    if(o.isOperator(last) && last != ')')
    {
        return false;
    }

    return true;
}

bool InputParser::validatePostfix(string input) {
    return true;
}

string InputParser::parsePostfix(string input)
{
    string str = copyString(input);

    bool isValid = validatePostfix(str);

    if(isValid)
    {
        return str;
    }
    else
    {
        throw invalid_argument("Invalid input: " + str);
        return "";
    }
}
