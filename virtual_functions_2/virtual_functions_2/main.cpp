//
//  main.cpp
//  virtual_functions_2
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

using namespace std;


class Pet
{
    string m_name;
    
public:
    Pet(string s) : m_name(s) {}
    virtual void speak(bool loud);
    virtual void move ();
};


class Snake:public Pet
{
public:
    Snake(string s) : Pet(s) {}
    virtual void speak(bool loud);
    virtual void move ();
};


class Bird:public Pet
{
public:
    Bird(string s) : Pet(s) {}
    virtual void speak(bool loud);
    virtual void move ();
};



class Fish:public Pet
{
public:
    Fish(string s) : Pet(s) {}
    virtual void speak(bool loud);
    virtual void move ();
};



void Pet::speak(bool loud)
{
}


void Pet::move()
{
    cout << "step ";
}


void Snake::speak(bool loud)
{
    cout << "hiss ";
}


void Snake::move()
{
    cout << "slither ";
}


void Bird::speak(bool loud)
{
    if (loud)
        cout << "squawk ";
    else
        cout << "chirp ";
}


void Bird::move()
{
    cout << "flap ";
}


void Fish::speak(bool loud)
{
    cout << "gurgle ";
}


void Fish::move()
{
    cout << "swim ";
}


void exercise(Pet& a, int n)
{
    for (int i = 0; i < n; i++)
        a.move();
    
    cout << endl;
}


void dance(Pet& a)
{
    a.speak(false);
    
    a.move();
    a.move();
    
    a.speak(true);
    
    a.move();
    
    a.speak(false);
    a.speak(false);
    
    cout << endl;
}


int main()
{
    int NUM_PETS = 3;
    Pet* pets[NUM_PETS];
    pets[0] = new Fish("Nemo");
    pets[1] = new Bird("Bird");
    pets[2] = new Snake("Snake");
}
