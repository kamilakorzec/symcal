#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>

using namespace std;

class InputParser 
{
public:
    string parseStandard(string input);
    string parseSuffix(string input);

private:
	string sanitize(string input);
    bool validateStandard(string input);
    bool validateSuffix(string input);
    string removeSpaces(string str);
    string copyString(string input);
};

#endif // INPUT_PARSER_H
