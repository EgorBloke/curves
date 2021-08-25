
#ifndef CURVES_H
#define CURVES_H

#include<iostream>
#include<cmath>
#include<limits>		



class Point;
std::ostream& operator<<(std::ostream& out, const std::pair<Point, Point>& p);		//перегрузка вывода для пары точек


class Point {	//
public:
	Point(double x=0.,double y=0.):x(x),y(y){}

	double x;
	double y;	
};

class Curves {		//базовый абстрактный класс для кривых
public:
	Curves(double x,double y):originPoint(x,y)		//конструктор принимает координаты начальной точки
	{

	}
	virtual std::pair<Point, Point> operator() (double t) = 0;	 //функтор для, принимает t  в качетве параметра 
			//возвращает пару из точек: первая = координаты от параметра t, вторая - ноль-вектор производной
			//метод виртуальный, перегружается в каждом классе

protected:
	Point originPoint;
};

class Line :public Curves {		// класс, описывающий прямые
public:
	Line(double x=0., double y=0.,double d=0.):Curves(x,y),d(d)			//делегирует начальные точки в конструткор базоваго класса и инициализирует d
	{

	}
	std::pair<Point, Point> operator() (double t) override;

protected:
	double d;
};



class Ellipse :public Curves{		//класс для эллипсов
public:
	Ellipse(double x = 0., double y = 0., double a = 1., double b=1.):Curves(x,y)
	{
		this->a = a == 0. ? 1 : abs(a);	//проверка на 0,  присваивает значение по модулю
		this->b = b == 0. ? 1 : abs(b);
	}
	std::pair<Point, Point> operator() (double t) override;
protected:
	double a;
	double b;
	
};

#endif // !CURVES_H
