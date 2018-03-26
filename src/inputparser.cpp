#include "lib/inputparser.h"
#include <stdexcept>
#include <algorithm>
#include <ctype.h>

string InputParser::copyString(string input) {
    char* str = new char[input.size() + 1];
    copy(input.begin(), input.end(), str);
    str[input.size()] = '\0';

    return string(str);
}

void InputParser::removeSpaces(string str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

string InputParser::parseStandard(string input)
{
    string str = sanitize(input);
    bool isValid = validateStandard(str);

    if(isValid)
    {
        return str;
    }
    else
    {
        throw invalid_argument("Invalid input");
        return "";
    }
}

string InputParser::sanitize(string input)
{
    string str = copyString(input);
    removeSpaces(str);

    return str;
}

bool InputParser::validateStandard(string input)
{
    int subsequentOperators = 0;
    int openedBrackets = 0;
    for(int i=0; i < input.length(); i++) {
        char c = input[i];
        if(!isdigit(c)) { //ignore all digits
            if(isalpha(c) && c != 'x') return false;
            else
            {   //it can't be digit, space or x - it must be an operator
                //there can be only one subsequent operator (different than bracket)
                if(c == '(') subsequentOperators++;
                else if(c == ')')
                {
                    if(openedBrackets < 1) return false;
                    openedBrackets--;
                }
                else
                {
                    if(subsequentOperators) return false;
                    subsequentOperators++;
                }
            }
        }
        else {
            if(subsequentOperators) subsequentOperators = 0;
        }
    }
    return true;
}

bool InputParser::validateSuffix(string input) {
    return true;
}

string InputParser::parseSuffix(string input)
{
    string str = copyString(input);

    bool isValid = validateSuffix(str);

    if(isValid)
    {
        return str;
    }
    else
    {
        throw invalid_argument("Invalid input");
        return "";
    }
}
