//
//  main.cpp
//  operator_overload
//
//  Created by Eric Ito on 10/24/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

class Point
{
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };
    
    Point operator+(Point q) {
        Point r = Point(0,0);
        r.x = this->x + q.x;
        r.y = this->y + q.y;
        return r;
    };
    
    Point& operator+=(Point p) {
        x += p.x;
        y += p.y;
        return *this;
    };
    
//    std::ostream& operator<<(std::ostream& os, Point const& p)
//    {
//        os << "(" << p.x << "," << p.y << ")" << std::endl;
//    };
    
};


int main(int argc, const char * argv[])
{

    Point t = Point(1,1);
    Point s = Point(2,2);
    Point z = t + s;
    std::cout << "x = " << z.x << " and y = " << z.y << std::endl;
    
    t += s;
    std::cout << "x = " << t.x << " and y = " << t.y << std::endl;
    
    
    Point p = Point(5, 7);
//    std::cout << p << std::endl;
    

    return 0;
}

