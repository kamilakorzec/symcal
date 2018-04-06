#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>

using namespace std;

class InputParser 
{
public:
    string parseInfix(string input);
    string parsePostfix(string input);

private:
	string sanitize(string input);
    bool validateInfix(string input);
    bool validatePostfix(string input);
    string removeSpaces(string str);
    string copyString(string input);
};

#endif // INPUT_PARSER_H
