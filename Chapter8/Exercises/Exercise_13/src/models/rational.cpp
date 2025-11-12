#include "pch/pch.h"
#include "models/rational.h"

namespace models
{
    rational::rational(const int& num, const int& den): numerator(num), denominator(den)
    {
        if(denominator == 0) throw std::runtime_error{"Devision by Zero"};
        simplify();
    }

    rational::~rational() {}

    void rational::simplify()
    {
        int a{numerator};
        int b{denominator};
        int t{0};
        while(b != 0)
        {
            t = b;
            b = a % b;
            a = t;
        }
        numerator /= a;
        denominator /= a;
        if(denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    double rational::approximate()
    {
        return static_cast<double>(numerator) / denominator;
    }

    bool rational::operator==(const rational& other) { return numerator == other.numerator && denominator == other.denominator; }
    bool rational::operator!=(const rational& other) { return numerator != other.numerator || denominator != other.denominator; }

    rational& rational::operator=(const rational& other)
    {
        if(this != &other)
        {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    rational rational::operator+(const rational& other)
    { 
        if(denominator == other.denominator)
        {
            return rational{numerator + other.numerator, denominator};
        }
        return rational{numerator * other.denominator + other.numerator * denominator, denominator * other.denominator}; 
    }

    rational& rational::operator+=(const rational& other)
    {
        if(denominator == other.denominator)
        {
            numerator += other.numerator;
            simplify();
            return *this;
        }
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator = denominator * other.denominator;
        simplify();
        return *this;
    }

    rational rational::operator-(const rational& other)
    { 
        if(denominator == other.denominator)
        {
            return rational{numerator - other.numerator, denominator};
        }
        return rational{numerator * other.denominator - other.numerator * denominator, denominator * other.denominator}; 
    }

    rational& rational::operator-=(const rational& other)
    {
        if(denominator == other.denominator)
        {
            numerator -= other.numerator;
            simplify();
            return *this;
        }
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator = denominator * other.denominator;
        simplify();
        return *this;
    }

    rational rational::operator*(const rational& other)
    {
        return rational{numerator * other.numerator, denominator * other.denominator};
    }

    rational& rational::operator*=(const rational& other)
    {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    rational rational::operator/(const rational& other)
    {
        return rational{numerator * other.denominator, denominator * other.numerator};
    }

    rational& rational::operator/=(const rational& other)
    {
        numerator = numerator * other.denominator;
        denominator = denominator * other.numerator;
        simplify();
        return *this;
    }
}

std::ostream& operator<<(std::ostream& os, const models::rational& ration)
{
    return os << ration.numerator << '/' << ration.denominator;
}