#ifndef POINT_H
#define POINT_H

/*
 * Point class
 * Represents 2D point (x,y)
 */
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
