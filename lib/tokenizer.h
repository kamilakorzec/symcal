#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "token.h"
#include <vector>
#include <string>

using namespace std;

class Tokenizer
{
public:
    vector<Token<string>> tokenizeStandard(string input);
    vector<Token<string>> tokenizeSuffix(string input);
};

#endif // TOKENIZER_H
