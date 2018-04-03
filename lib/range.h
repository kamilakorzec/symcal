#ifndef RANGE_H
#define RANGE_H


template <typename T> class Range
{
public:
    Range();
    Range(T from, T to);
    T getFrom() { return from; }
    T getTo() { return to; }

private:
	T from;
	T to;
};

#endif // RANGE_H