//
//  main.cpp
//  constructors
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

struct Base
{
    Base() { std::cout << "Base()\n"; }
};

struct Sub : public Base
{
    Sub() { std::cout << "Sub()\n"; }
    Sub(const Sub& other)
    {
        std::cout << "Sub copy\n";
    }
};

void process(Sub b)
{
    
}

int main(int argc, const char * argv[])
{

    Sub();
    
    return 0;
}

