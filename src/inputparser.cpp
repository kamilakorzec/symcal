#include "inputparser.h"

#include <algorithm>

string InputParser::copyString(string input) {
    char* str = new char[input.size() + 1];
    copy(input.begin(), input.end(), str);
    str[input.size()] = '\0';

    return string(str);
}

void InputParser::removeSpaces(string str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

string InputParser::parse(string input)
{
    string str = copyString(input);

    return str;
}

string InputParser::sanitize(string input)
{
	return string();
}

bool InputParser::validate(string input)
{
	return false;
}
