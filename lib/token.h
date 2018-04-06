#ifndef TOKEN_H
#define TOKEN_H

#include<string>

using namespace std;

/*
 * Token class
 * Represents single token with its value
 * Contains two flags to determine wheter token is variable or operator
 */
class Token
{
public:
    Token();
    Token(string v, bool o, bool var);
    string getValue() { return value; }
    bool isOperator() { return isOp; }
    bool isVariable() { return isVar; }

private:
    bool isOp;
    bool isVar;
    string value;

};

#endif // TOKEN_H
