//
//  main.cpp
//  nonvirtualinterface
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

//
// "template method"
struct Game
{
    void play(int players)
    {
        // set up the board
        for (int i = 0; i < players; i++)
        {
            // player move
        }
    }
    
    virtual void init();
    virtual void playermove(int i);
    virtual void finish();
    virtual void displayWinner();
};

struct Chess : public Game
{
    // setup chess
};

struct Poker : public Game
{
    
};

struct Shape
{
    void draw() {
        setup();
        //
        // doDraw is pure virtual
        doDraw();
        teardown();
    }
    // make and call set up first
    //
    virtual ~Shape();
private:
    void setup() { std::cout << "Setup\n"; }
    void teardown() { std::cout << "Teardown\n"; }
    virtual void doDraw() = 0;
};

struct Circle : public Shape
{
    void doDraw()
    {
        std::cout << "Circle\n";
    }
};

int main(int argc, const char * argv[])
{

//    Shape* shapes[5];
//    shapes[0] = new Circle;
//    shapes[1] = new Line;
//    shapes[2] = new Circle;
//    shapes[3] = new Circle;
//    shapes[4] = new Line;
//    
//    drawPicture(shapes, shapes+5);
    return 0;
}

