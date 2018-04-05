#ifndef POINT_H
#define POINT_H



class Point
{
public:
    Point(double dx, double dy)
    {
        x = dx;
        y = dy;
    }
    double getX() { return x; }
    double getY() { return y; }
private:
    double x;
    double y;
};

#endif // POINT_H
