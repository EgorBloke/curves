#include "curves.h"

static const double PI = 3.14159;

std::pair<Point, Point> Ellipse::operator()(double t)       //перегруженный оператор (t) возвращает точку на конусе и ноль-вектор первой производной
{
    t = t - (2 * PI) * (int)floor(abs(t) / (2 * PI));       //приводит значение t к диапазону от 0 до 2*Пи 
    double x = a * cos(t)+this->originPoint.x;      //расчет координат от параметра t и базововой точки
    double y = b * sin(t)+this->originPoint.y;
    double xDer; //координаты ноль-вектора производной
    double yDer;
    double Der;     //значение производной

    if (
        (abs(t)<PI + PI / 1.0e+10 && abs(t) > PI - PI / 1.0e+10)||
        (abs(t) <  PI / 1.0e+10 && abs(t) > - PI / 1.0e+10)
        )   // граничное условие для значения, кратного ПИ, когда производная равна бесконечности
           
    {
        xDer = 0.;
        yDer = 1.;

    }
    else if (
        (abs(t) < PI / 2 + PI / 1.0e+10 && abs(t) > PI / 2 - PI / 1.0e+10) ||
        (abs(t) < 3 * PI / 2 + PI / 1.0e+10 && abs(t) >3 * PI / 2 - PI / 1.0e+10)
        ) // граничное условие для значения, кратного ПИ, когда производная равна 0
    {
        xDer = 1.;
        yDer = 0.;
    }
    else     //общий случай    
    {
        Der = -b / (a * tan(t));    //проихводная от параметрического уравнения эллипса
        xDer = x;
        yDer = Der * xDer;        
    }
    return std::make_pair<Point, Point>(Point(x, y), Point(xDer, yDer));
}

std::pair<Point, Point> Line::operator()(double t)      //перегруженный оператор (t) возвращает точку на прямой и ноль-вектор первой производной
{
    double x = t + this->originPoint.x;         //расчет координат от параметра t и базововой точки
    double y = d * t + this->originPoint.y;
    double xDer;
    double yDer;
    if (abs(d) > 1.0e+20)       //прямая параллельна оси У
    {
        x = this->originPoint.x;
        y = this->originPoint.y;
        xDer=0.;
        yDer=1.;
    }
    else if (abs(d) < 1.0e-20)      //прямая параллельна оси Х
    {
        x = t;
        y = this->originPoint.y;
        xDer=1.;
        yDer=0.;
    }
    else            //общий случай
    {
        xDer = 1 / d;
        yDer = 1.;
    }
    return std::make_pair<Point, Point>(Point(x, y), Point(xDer, yDer));
}

std::ostream& operator<<(std::ostream& out, const std::pair<Point, Point>& p)
{
    out << "x = \t" << p.first.x << ";\t y = \t" << p.first.y << "\t" << "Derivative: (" << p.second.x << ", " << p.second.y << ")";
    return out;
}
