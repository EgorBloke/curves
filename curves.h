
#ifndef CURVES_H
#define CURVES_H

#include<iostream>
#include<cmath>
#include<limits>		//??

//static const double PI;		//FIXIT

class Point;
std::ostream& operator<<(std::ostream& out, const std::pair<Point, Point>& p); 


class Point {
public:
	Point(double x=0.,double y=0.):x(x),y(y){}

	double x;
	double y;	
};

class Curves {
public:
	Curves(double x,double y):originPoint(x,y)
	{

	}
	virtual std::pair<Point, Point> operator() (double t) = 0;

private:
	Point originPoint;
};

class Line :public Curves {
public:
	Line(double x=0., double y=0.,double d=0.):Curves(x,y),d(d)
	{

	}
	std::pair<Point, Point> operator() (double t) override;

private:
	double d;
};

class Normal : public Curves {
public:
	Normal(double x = 0., double y = 0.):Curves(x, y)
	{

	}
private:
	Point Der = Point(0, 1);

};

class Ellipse :public Curves{
public:
	Ellipse(double x = 0., double y = 0., double rX = 0., double rY=0.):Curves(x,y),a(rX),b(rY)
	{
		
	}
	std::pair<Point, Point> operator() (double t) override;
private:
	double a;
	double b;
	
};

#endif // !CURVES_H
