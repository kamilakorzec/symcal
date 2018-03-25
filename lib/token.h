#ifndef TOKEN_H
#define TOKEN_H


template <typename T> class Token
{
public:
    Token(T v, bool o);
    T getValue() { return value; }
    bool isOperator() { return isOp; }

private:
    bool isOp;
    T value;

};

#endif // TOKEN_H
