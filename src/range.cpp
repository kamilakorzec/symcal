#include "lib/range.h"


template <typename T>
Range<T>::Range(T f, T t)
{
    from = f;
    to = t;
}

template <typename T>
Range<T>::Range()
{
    from = (T)0;
    to = (T)0;
}

template class Range<double>;
