
#include <iostream>
#include"curves.h"
#include<vector>
#include<algorithm>
int main()
{
    std::vector<Curves*> vec;
    vec.push_back(new Line(2.54, -3.2, 6.5));
    vec.push_back(new Ellipse(7.54, 3.2, 6.5, 3.5));
    for (auto v : vec) {
        std::cout << v->operator()(2.2) <<std:: endl;;
    }
    
}

