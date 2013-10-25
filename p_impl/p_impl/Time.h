//
//  Time.h
//  p_impl
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#ifndef __p_impl__Time__
#define __p_impl__Time__

#include <iostream>

class Time
{
public:
    int hours() const;
    int mins() const;
    int secs() const;
    int ticks() const;
    
    void setHours(int h);
    void setMins(int m);
    void setSecs(int s);
    void setTicks(int ticks);
    
    void print();
private:
    struct TimeImpl;
    TimeImpl* pImpl;
};

Time operator+(Time a, Time b);

#endif /* defined(__p_impl__Time__) */
