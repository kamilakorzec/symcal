#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"
#include <vector>
#include <string>

using namespace std;

/*
 * Class Tokenizer
 * Consists of two methods converting string into a vector of Tokens
 * Used in parser
 */
class Tokenizer
{
public:
    vector<Token> tokenizeInfix(string input);
    vector<Token> tokenizePostfix(string input);
};

#endif // TOKENIZER_H
