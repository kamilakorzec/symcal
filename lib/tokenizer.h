#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"
#include <vector>
#include <string>

using namespace std;

class Tokenizer
{
public:
    vector<Token> tokenizeInfix(string input);
    vector<Token> tokenizePostfix(string input);
};

#endif // TOKENIZER_H
