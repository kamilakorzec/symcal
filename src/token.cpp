#include "lib/token.h"

Token::Token(string v, bool o)
{
    value = v;
    isOp = o;
}

Token::Token()
{
    value = "";
    isOp = false;
}
