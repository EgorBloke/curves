
#ifndef CURVES_H
#define CURVES_H

#include<iostream>
#include<cmath>
#include<limits>		



class Point;
std::ostream& operator<<(std::ostream& out, const std::pair<Point, Point>& p);		//���������� ������ ��� ���� �����


class Point {	//
public:
	Point(double x=0.,double y=0.):x(x),y(y){}

	double x;
	double y;	
};

class Curves {		//������� ����������� ����� ��� ������
public:
	Curves(double x,double y):originPoint(x,y)		//����������� ��������� ���������� ��������� �����
	{

	}
	virtual std::pair<Point, Point> operator() (double t) = 0;	 //������� ���, ��������� t  � ������� ��������� 
			//���������� ���� �� �����: ������ = ���������� �� ��������� t, ������ - ����-������ �����������
			//����� �����������, ������������� � ������ ������

protected:
	Point originPoint;
};

class Line :public Curves {		// �����, ����������� ������
public:
	Line(double x=0., double y=0.,double d=0.):Curves(x,y),d(d)			//���������� ��������� ����� � ����������� �������� ������ � �������������� d
	{

	}
	std::pair<Point, Point> operator() (double t) override;

protected:
	double d;
};



class Ellipse :public Curves{		//����� ��� ��������
public:
	Ellipse(double x = 0., double y = 0., double a = 1., double b=1.):Curves(x,y)
	{
		this->a = a == 0. ? 1 : abs(a);	//�������� �� 0,  ����������� �������� �� ������
		this->b = b == 0. ? 1 : abs(b);
	}
	std::pair<Point, Point> operator() (double t) override;
protected:
	double a;
	double b;
	
};

#endif // !CURVES_H
