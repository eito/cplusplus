//
//  main.cpp
//  operator_overload_lab
//
//  Created by Eric Ito on 10/24/13.
//  Copyright (c) 2013 Eric Ito. All rights reserved.
//

#include <iostream>

class Rational
{
public:
    Rational() { n = 0; d = 0;};
    Rational(int num, int den) {
        n = num;
        d = den;
        this->reduce();
    };
    
    int n; // numerator
    int d; // denominator
    
    void reduce()
    {
        //
        // if denominator less than 0,  *=-1
        if (d < 0) {
            d = -d;
            n = -n;
        }
        
        int g = n < 0 ? gcd(-n, d) : gcd(n, d);
        
        n /= g;
        d /= g;
    };
    
    int gcd(int i, int j)
    {
        if (j == 0)
            return i;
        else
            return gcd(j, i % j);
    };
    
    Rational& operator+=(Rational a)
    {
        n = n * a.d + d * a.n;
        d = d * a.d;
        this->reduce();
        return *this;
    };
    
    Rational& operator-=(Rational a)
    {
        n = n*a.d - a.n*d;
        d = a.d* d;
        this->reduce();
        return *this;
    };
    
    Rational& operator*=(Rational a)
    {
        n *= a.n;
        d *= a.d;
        return *this;
    };
    
    Rational& operator/=(Rational a)
    {
        n /= a.n;
        d /= a.d;
        return *this;
    };
};

bool operator==(Rational a, Rational b)
{
    return a.n == b.n && a.d == b.d;
};

bool operator!=(Rational a, Rational b)
{
    return a.n != b.n || a.d != b.d;
};

//
// 1/2 <= 1/3
bool operator<=(Rational a, Rational b)
{
    return (a.n * b.d) <= (a.d * b.n);
};

bool operator>=(Rational a, Rational b)
{
    return (a.n * b.d) >= (a.d * b.n);
};

bool operator< (Rational a, Rational b)
{
    return (a.n * b.d) < (a.d * b.n);
};

bool operator> (Rational a, Rational b)
{
    return (a.n * b.d) > (a.d * b.n);
};

std::ostream& operator<<(std::ostream& s, Rational a)
{
    s << a.n << "/" << a.d << std::endl;
    return s;
}

//
// 1/2 + 1/3 == 5/6
Rational operator+(Rational a, Rational b)
{
    return Rational(a.n * b.d + b.n * a.d, a.d*b.d);
};

Rational operator-(Rational a)
{
    return Rational(-a.n, a.d);
};

//
// 1/2 - 1/3 = 3/6 - 2/6 = 1/6
Rational operator-(Rational a, Rational b)
{
    return Rational(a.n*b.d - b.n*a.d, a.d*b.d);
};

Rational operator*(Rational a, Rational b)
{
    return Rational(a.n*b.n, a.d*b.d);
};

//
// 1/2 / 1/3 = 1/2 * 3/1 = 3/2
Rational operator/(Rational a, Rational b)
{
    return Rational(a.n*b.d, a.d*b.n);
};

Rational operator*(Rational a, int c)
{
    return Rational(a.n * c, a.d);
};

Rational operator*(int c, Rational a)
{
    return Rational(a.n * c, a.d);
};



int main(int argc, const char * argv[])
{

    Rational a = Rational(1, 2);
    Rational b = Rational(1, 3);
    Rational c = a + b;
    std::cout << c << std::endl;
    
    //
    // addition
    a = Rational(1, 3);
    b = Rational(1, 6);
    c = a + b;
    std::cout << c << std::endl;
    
    //
    // subtract
    a = Rational(1, 3);
    b = Rational(1, 6);
    c = a - b;
    std::cout << c << std::endl;
    
    //
    // multiply
    a = Rational(1, 3);
    b = Rational(1, 6);
    c = a * b;
    std::cout << c << std::endl;
    
    //
    // divide
    a = Rational(1, 3);
    b = Rational(1, 6);
    c = a / b;
    std::cout << c << std::endl;
    
    //
    // make a negative
    a = Rational(1, 3);
    c = -a;
    std::cout << c << std::endl;
    
    //
    // plus equals
    a = Rational(1, 3);
    a += Rational(1, 3);
    std::cout << a << std::endl;
    
    //
    // minus equals
    a = Rational(2, 3);
    a -= Rational(1, 3);
    std::cout << a << std::endl;
    
    //
    // times equals
    a = Rational(1, 3);
    b = Rational(2, 3);
    a *= b;
    std::cout << a << std::endl;
    
    //
    // divided by equals
    a = Rational(3, 6);
    b = Rational(1, 2);
    a /= b;
    std::cout << a << std::endl;
    
    //
    // less than or equal
    a = Rational(1, 3);
    b = Rational(1, 3);
    if (a <= b) {
        std::cout << "less than or equal" << std::endl;
    }

    a = Rational(1, 3);
    b = Rational(1, 2);
    if (a <= b) {
        std::cout << "less than or equal" << std::endl;
    }

    //
    // greater than or equal
    a = Rational(1, 2);
    b = Rational(1, 3);
    if (a >= b) {
        std::cout << "greater than or equal" << std::endl;
    }
    
    a = Rational(1, 2);
    b = Rational(1, 2);
    if (a >= b) {
        std::cout << "greater than or equal" << std::endl;
    }

    //
    // less than
    a = Rational(1, 3);
    b = Rational(1, 2);
    if (a < b) {
        std::cout << "less than" << std::endl;
    }
    
    a = Rational(1, 2);
    b = Rational(1, 2);
    if (a < b) {
        std::cout << "less than" << std::endl;
    }
    
    //
    // greater than
    a = Rational(1, 2);
    b = Rational(1, 3);
    if (a > b) {
        std::cout << "greater than" << std::endl;
    }
    
    a = Rational(1, 2);
    b = Rational(1, 2);
    if (a > b) {
        std::cout << "greater than" << std::endl;
    }

    a = Rational(1, 2);
    b = 5 * a;
    std::cout << b << std::endl;

    a = Rational(1, 2);
    b = a * 5;
    std::cout << b << std::endl;
    

    return 0;
}

