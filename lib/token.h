#ifndef TOKEN_H
#define TOKEN_H

#include<string>

using namespace std;

class Token
{
public:
    Token();
    Token(string v, bool o);
    string getValue() { return value; }
    bool isOperator() { return isOp; }

private:
    bool isOp;
    string value;

};

#endif // TOKEN_H
