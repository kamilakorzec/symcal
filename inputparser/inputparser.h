#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>


class InputParser 
{
public:
	string parse(string input);
	~InputParser;

private:
	string sanitize(string input);
	bool validate(string input);

};

#endif // INPUT_PARSER_H
