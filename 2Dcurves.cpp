
#include <iostream>
#include"curves.h"
#include<vector>
#include<algorithm>
extern const double PI = 3.14159;
int main()
{
    std::vector<Curves*> vec;

    //for (int i = 0; i < 20; ++i) {
    //    if (rand() % 2 == 1) 
    //    {
    //        vec.push_back(new Line(
    //            ((double)rand() / RAND_MAX - 0.5) * 10,
    //            ((double)rand() / RAND_MAX - 0.5) * 10,
    //            (double)RAND_MAX / double((double)rand() - RAND_MAX / 2)
    //        ));
    //    }
    //    else
    //    {
    //        vec.push_back(new Ellipse(
    //            ((double)rand() / RAND_MAX - 0.5) * 10,
    //            ((double)rand() / RAND_MAX - 0.5) * 10,
    //            (double)RAND_MAX / double((double)rand() - RAND_MAX / 2),
    //            (double)RAND_MAX / double((double)rand() - RAND_MAX / 2)
    //        ));
    //    }
    //}
    for (int i = 0; i < 20; ++i) {
        if (rand() % 2 == 1)
        {
            vec.push_back(new Line(
                ((double)rand() / RAND_MAX - 0.5) * 10,
                ((double)rand() / RAND_MAX - 0.5) * 10,
                (double)RAND_MAX / double((double)rand() - RAND_MAX / 2)
            ));
        }
        else
        {
            vec.push_back(new Ellipse(
                0,
                0,
                (double)RAND_MAX / double((double)rand() - RAND_MAX / 2),
                (double)RAND_MAX / double((double)rand() - RAND_MAX / 2)
            ));
        }
    }
    vec.push_back(new Line(2.54, -3.2, 6.5));
    vec.push_back(new Line((double)1000 / double((double)500 - (double)1000 / 2)));
    vec.push_back(new Ellipse(0, 0, 6.5, 3.5));
    vec.push_back(new Ellipse(1, 1, 6.5, 3.5));

    for (auto v : vec) {
        std::cout << typeid(*v).name()<<":\t"<<v->operator()(PI) <<std:: endl;;
    }
    
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(-PI) << std::endl;;
    }
    for (auto v : vec) {
        std::cout << typeid(*v).name() << ":\t" << v->operator()(-PI/2) << std::endl;;
    }
}

