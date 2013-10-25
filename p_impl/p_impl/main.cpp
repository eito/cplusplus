//
//  main.cpp
//  p_impl
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>
#include "Time.h"

int main(int argc, const char * argv[])
{

    Time t, s, z;
    t.setHours(10);
    s.setMins(74);
    z = t + s;
}

