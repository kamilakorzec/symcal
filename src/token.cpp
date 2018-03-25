#include "token.h"

template <typename T>
Token<T>::Token(T v, bool o) {
    value = v;
    isOp = o;
}
