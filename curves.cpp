#include "curves.h"

static const double PI = 3.14159;

std::pair<Point, Point> Ellipse::operator()(double t)
{
    t = t - (2 * PI) * (int)floor(abs(t) / (2 * PI));       //
    double x = a * cos(t);
    double y = b * sin(t);
    double xDer;
    double yDer;
    
    //if (t < 2 * PI)      //FIXIT
    //{
    //    yDer = -2 * x / (b * a * a * sqrt(1 - x * x / (a * a)));
    //}
    //else
    //{
    //    yDer = 2 * x / (b * a * a * sqrt(1 - x * x / (a * a)));
    //}
    if (abs(t)<PI + PI / 100000 && abs(t) > PI - PI / 100000)
    {
        xDer = 0;
        yDer = 1;

    }
    else
    {
        xDer = x;
        yDer = -b / (a * tan(t));
    }
    return std::pair<Point, Point>(Point(x,y),Point(xDer,yDer));
}

std::pair<Point, Point> Line::operator()(double t)
{
    double x = t;
    double y = d * t;
    double xDer{ 0 };
    double yDer{ 0 };
    if (abs(d) > 1.0e+20)
    {
        double xDer=0;
        double yDer=1;
    }
    else if (abs(d) < 1.0e-20){
        double xDer=1;
        double yDer=0;
    }
    else {
        double xDer = 1 / d;
        double yDer = 1;
    }
    return std::pair<Point, Point>(Point(x, y), Point(xDer, yDer));
}

std::ostream& operator<<(std::ostream& out, const std::pair<Point, Point>& p)
{
    out << "x = \t" << p.first.x << ";\t y = " << p.first.y << "\t" << "Derivative: (" << p.second.x << ", " << p.second.y << ')';
    return out;
}
