//
//  main.cpp
//  dynamic_memory_2
//
//  Created by Eric Ito on 10/24/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

using namespace std;

class Number
{
public:
    
    Number() { m_size = 0; m_digits = 0; };
    
    ~Number()
    {
        delete [] m_digits;
    };
    
    void read (istream& is)
    {
        delete [] m_digits;
        
        // read in string
        string s;
        is >> s;
        //
        // figure out size
        m_size = (int)s.length();
        m_digits = new ushort[m_size];
        for (int i = 0; i < m_size; i++) {
            m_digits[i] = s[i];
        }
        
    };
    void print(ostream& os) const
    {
        if (m_digits == 0)
        {
            os << "undefined";
        }
        else {
            for (int i = 0; i < m_size; i++) {
                os << m_digits[i] - '0';
            }
            os << endl;
        }
    }
    bool defined() const
    {
        return (m_digits != 0);
    }
private:
    int     m_size;
    ushort* m_digits;
};

istream& operator>>(istream& is, Number& num)
{
    num.read(is);
    return is;
}

ostream& operator<<(ostream& os, const Number& num)
{
    num.print(os);
    return os;
}

int main(int argc, const char * argv[])
{

    Number a;
    if (!a.defined()) {
        cout << "Not defined yet" << endl;
    }
    cout << "number? ";
    cin >> a;
    cout << a << endl;

    return 0;
}

