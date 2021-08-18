#include "curves.h"

std::pair<Point, Point> Ellipse::operator()(double t)
{
    t = t-(2*3.14159)*(int)floor(abs(t)/(2*3.14159));
    double x = rX * cos(t);
    double y = rX * sin(t);
    double yDer;
    if (t < 2 * 3.14159)      //FIXIT
    {
        yDer = -2 * x / (rY * rX * rX * sqrt(1 - x * x / (rX * rX)));
    }
    else
    {
        yDer = 2 * x / (rY * rX * rX * sqrt(1 - x * x / (rX * rX)));
    }
    
    return std::pair<Point, Point>(Point(x,y),Point(x,yDer));
}

std::pair<Point, Point> Line::operator()(double t)
{
    double x = t;
    double y = d * t;     
    return std::pair<Point, Point>(Point(x, y), Point(x, d));
}

std::ostream& operator<<(std::ostream& out, const std::pair<Point, Point>& p)
{
    out << "x = " << p.first.x << "; y = " << p.first.y << "\t" << "Derivative: (" << p.second.x << ', ' << p.second.y << ')';
    return out;
}
