#pragma once

namespace models
{
    struct rational
    {
        int numerator;
        int denominator;

        rational(const int& num, const int& den);
        ~rational();

        void simplify();
        double approximate();

        bool operator==(const rational& other);
        bool operator!=(const rational& other);

        rational operator+(const rational& other);
        rational& operator+=(const rational& other);

        rational operator-(const rational& other);
        rational& operator-=(const rational& other);

        rational operator*(const rational& other);
        rational& operator*=(const rational& other);

        rational operator/(const rational& other);
        rational& operator/=(const rational& other);

        rational& operator=(const rational& other);
    };
}

std::ostream& operator<<(std::ostream& os, const models::rational& ration);