//
//  main.cpp
//  pointers
//
//  Created by Eric Ito on 10/24/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

void print(int *begin, int *end)
{
    if (!begin || !end) {
        std::cout << "One or more are NULL\n";
        return;
    }
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[])
{

    int a[5];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    int *begin = a;
    print (begin, begin+5);
    return 0;
}

