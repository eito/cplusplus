//
//  Time.cpp
//  p_impl
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include "Time.h"

struct Time::TimeImpl
{
    int m_hours;
    int m_seconds;
    int m_minutes;
    int m_ticks;
};


int Time::hours() const
{
    return pImpl->m_hours;
}

int Time::mins() const
{
    return pImpl->m_minutes;
}

int Time::secs() const
{
    return pImpl->m_seconds;
}

int Time::ticks() const
{
    return pImpl->m_ticks;
}

void Time::setHours(int h)
{
    pImpl->m_hours = h;
}

void Time::setMins(int m)
{
    pImpl->m_minutes = m;
}

void Time::setSecs(int s)
{
    pImpl->m_seconds = s;
}

void Time::setTicks(int t)
{
    pImpl->m_ticks = t;
}

void Time::print()
{
    std::cout << "hours: " << this->hours() << " mins: " << this->mins() << " secs: " << this->secs() << std::endl;
}
Time operator+(Time a, Time b)
{
    Time c;
    c.setHours(a.hours() + b.hours());
    c.setMins(a.mins() + b.mins());
    c.setSecs(a.secs() + b.secs());
    c.setTicks(a.ticks() + b.ticks());
    return c;
}