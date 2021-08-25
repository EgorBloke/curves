#include "curves.h"

static const double PI = 3.14159;

std::pair<Point, Point> Ellipse::operator()(double t)       //������������� �������� (t) ���������� ����� �� ������ � ����-������ ������ �����������
{
    t = t - (2 * PI) * (int)floor(abs(t) / (2 * PI));       //�������� �������� t � ��������� �� 0 �� 2*�� 
    double x = a * cos(t)+this->originPoint.x;      //������ ��������� �� ��������� t � ��������� �����
    double y = b * sin(t)+this->originPoint.y;
    double xDer; //���������� ����-������� �����������
    double yDer;
    double Der;     //�������� �����������

    if (
        (abs(t)<PI + PI / 1.0e+10 && abs(t) > PI - PI / 1.0e+10)||
        (abs(t) <  PI / 1.0e+10 && abs(t) > - PI / 1.0e+10)
        )   // ��������� ������� ��� ��������, �������� ��, ����� ����������� ����� �������������
           
    {
        xDer = 0.;
        yDer = 1.;

    }
    else if (
        (abs(t) < PI / 2 + PI / 1.0e+10 && abs(t) > PI / 2 - PI / 1.0e+10) ||
        (abs(t) < 3 * PI / 2 + PI / 1.0e+10 && abs(t) >3 * PI / 2 - PI / 1.0e+10)
        ) // ��������� ������� ��� ��������, �������� ��, ����� ����������� ����� 0
    {
        xDer = 1.;
        yDer = 0.;
    }
    else     //����� ������    
    {
        Der = -b / (a * tan(t));    //����������� �� ���������������� ��������� �������
        xDer = x;
        yDer = Der * xDer;        
    }
    return std::make_pair<Point, Point>(Point(x, y), Point(xDer, yDer));
}

std::pair<Point, Point> Line::operator()(double t)      //������������� �������� (t) ���������� ����� �� ������ � ����-������ ������ �����������
{
    double x = t + this->originPoint.x;         //������ ��������� �� ��������� t � ��������� �����
    double y = d * t + this->originPoint.y;
    double xDer;
    double yDer;
    if (abs(d) > 1.0e+20)       //������ ����������� ��� �
    {
        x = this->originPoint.x;
        y = this->originPoint.y;
        xDer=0.;
        yDer=1.;
    }
    else if (abs(d) < 1.0e-20)      //������ ����������� ��� �
    {
        x = t;
        y = this->originPoint.y;
        xDer=1.;
        yDer=0.;
    }
    else            //����� ������
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
