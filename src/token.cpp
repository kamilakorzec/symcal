#include "lib/token.h"

Token::Token(string v, bool o, bool var)
{
    value = v;
    isOp = o;
    isVar = var;
}

Token::Token()
{
    value = "";
    isOp = false;
    isVar = false;
}
