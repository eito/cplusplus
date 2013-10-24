//
//  main.cpp
//  copyswap
//
//  Created by Eric Ito on 10/24/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>
#include <string>

class DynArray
{
    DynArray(int size = 0)
    {
        m_size = size;
        if (m_size > 0)
        {
            m_data = new int[m_size];
        }
        else
        {
            m_data = 0;
        }
    }
    
    ~DynArray()
    {
        delete [] m_data;
    }
    
    DynArray(const DynArray& other)
    {
        m_size = other.m_size;
        m_data = new int[m_size];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }

    //
    // either of the next two are permissible
    //
    // this implicitly creates a copy 
    DynArray& operator=(DynArray tmp)
    {
        //
        // object in good state at this point if exception occurs above
        
        //
        // swap the copy's stuff into ours
        //
        // swap should never throw an exception
        using std::swap;
        swap(m_size, tmp.m_size);
        swap(m_data, tmp.m_data);
        return *this;
    };
    
    DynArray& operator=(const DynArray& other)
    {
        //
        // if exception happens in copy constructor, code bails after the following line
        DynArray tmp(other);
        
        //
        // object in good state at this point if exception occurs above
        
        //
        // swap the copy's stuff into ours
        //
        // swap should never throw an exception
        using std::swap;
        swap(m_size, tmp.m_size);
        swap(m_data, tmp.m_data);
        return *this;
    };
    
public:
private:
    int m_size;
    int *m_data;
};

int main(int argc, const char * argv[])
{

    

    return 0;
}

