
#include <iostream>
#include"curves.h"
#include<vector>
#include<algorithm>
#include<memory>
const double PI = 3.14159;
int main()
{      
    std::vector<std::shared_ptr<Curves>> vec;       //вектор указателей на базовый класс Curves


    vec.push_back(std::make_shared<Line> (2.54, -3.2, 6.5));
    vec.push_back(std::make_shared<Line>(2.54, -3.2, 0));
    vec.push_back(std::make_shared<Line> (0, 0, 1));
    vec.push_back(std::make_shared<Line> (2, 1, 1));
    vec.push_back(std::make_shared<Ellipse>(0, 0, 1, 1));
    vec.push_back(std::make_shared<Ellipse>(0, 0, 6.5, 3.5));
    vec.push_back(std::make_shared<Ellipse>(1, 1, 6.5, 3.5));
    vec.push_back(std::make_shared<Ellipse>(0, 0, 0, 1));
    vec.push_back(std::make_shared<Ellipse>(1, 1, 1, 0));

    //тесты граничных условий и общего случая
    double t = -PI / 2;
    std::cout << "t = " << t << std::endl;
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(t) << std::endl;
    }

    t = PI / 4;
    std::cout << "t = " << t << std::endl;
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(t) << std::endl;

    }

    t = 3*PI / 2;
    std::cout << "t = " << t << std::endl;
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(t) << std::endl;
    }

    t = PI;
    std::cout << "t = " << t << std::endl;
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(t) << std::endl;

    }

    t = -PI / 4;
    std::cout << "t = " << t << std::endl;
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(t) << std::endl;

    }

    t = 0.;
    std::cout << "t = " << t << std::endl;
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(t) << std::endl;
    }
}

