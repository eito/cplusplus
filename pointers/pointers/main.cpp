//
//  main.cpp
//  pointers
//
//  Created by Eric Ito on 10/24/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    int a[5];
    a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5;

    int *p = a;
    for (int i  = 0; i < 5; ++i, ++p) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
    return 0;
}

