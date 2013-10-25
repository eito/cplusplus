//
//  main.cpp
//  containers
//
//  Created by Eric Ito on 10/25/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//void print(int x)
//{
//    std::cout << x << " ";
//}

struct Print
{
    void operator()(int x)
    {
        std::cout << x << " ";
    }
};

struct Equals
{
    int m_n;
    Equals(int n) : m_n(n) {}
    bool operator()(int x) { return m_n == x; }
};

int main(int argc, const char * argv[])
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(10);
    v.push_back(16);
    v.push_back(8);
    v.push_back(10);
    v.push_back(16);
    v.push_back(4);
    v.push_back(13);
    v.push_back(2);
    v.push_back(16);
    v.push_back(10);
    v.push_back(16);    
    
    for_each(v.begin(), v.end(), Print());
    
    std::cout << std::endl;
    
    Print tmp;
    for_each(v.begin(), v.end(), tmp);
    
    std::cout << std::endl;
    
    for (int x : v) {
        std::cout << x << " ";
    }
    
    std::cout << std::endl;
    
    typedef std::vector<int>::iterator Iter;
    
    //
    // this wont work if 16 is at the end of vector
//    for (Iter it = v.begin(); it != v.end(); it++) {
//        if (*it == 16) {
//            v.erase(it);
//        }
//    }
    
    //
    // one way
    Iter newEnd = remove_if(v.begin(), v.end(), Equals(16));
    v.erase(newEnd, v.end());
    
    //
    // alternate way
    v.erase(remove_if(v.begin(), v.end(), Equals(10)), v.end());
    
    
    for (int x : v) {
        std::cout << x << " ";
    }

}

