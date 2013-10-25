//
//  main.cpp
//  shapes
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

struct Shape
{
    virtual void draw() { std::cout << "Shape\n"; }
    virtual ~Shape() { std::cout << "~Shape\n"; }
};

struct Circle : public Shape
{
    //
    // this virtual is NOT needed because base has it
    virtual void draw() { std::cout << "Circle\n"; }
    ~Circle() { std::cout << "~Circle\n"; }
};

struct Line : public Shape
{
    //
    // this virtual is NOT needed because base has it
    virtual void draw() { std::cout << "Line\n"; }
    ~Line() { std::cout << "~Line\n"; }
};

struct Rect
{
    //
    // only use virtual when you need it!
    virtual void draw() {}
};

void drawPicture(Shape** begin, Shape** end)
{
    while (begin != end) {
        (*begin)->draw();
        ++begin;
    }
}

void deleteShapes(Shape** begin, Shape** end)
{
    while (begin != end) {
        delete *begin;
        ++begin;
    }
}
int main(int argc, const char * argv[])
{
    std::cout << sizeof(Rect) << "\n";
    
    Shape* shapes[5];
    shapes[0] = new Circle;
    shapes[1] = new Line;
    shapes[2] = new Circle;
    shapes[3] = new Circle;
    shapes[4] = new Line;
    
    drawPicture(shapes, shapes+5);
    
    deleteShapes(shapes, shapes + 5);
    return 0;
}

