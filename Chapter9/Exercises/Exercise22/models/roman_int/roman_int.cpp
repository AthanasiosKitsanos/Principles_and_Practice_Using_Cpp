#include "roman_int.h"
#include <cstring>

roman_int::roman_int(): decimal(0), is_valid(true) {}

roman_int::roman_int(const int value): decimal(value), is_valid(true) {}

roman_int::roman_int(const bool valid): decimal(0), is_valid(valid) {}

roman_int::roman_int(const roman_int& other): decimal(other.decimal), is_valid(other.is_valid) {}

roman_int::~roman_int() {}

// Returns the equivalent Roman Numeral
char* roman_int::decimal_to_roman() const noexcept
{
    if(!is_valid) return nullptr; // if not in valid state, do nothing
    int temp_decimal{decimal}; // store the value in a temporarily variable

    int len{0}; // len is used for the length of the final result

    // Calculate the lenght
    for(const std::pair<int, const char*> p: roman_vector)
    {
        while(temp_decimal >= p.first)
        {
            len += strlen(p.second);
            temp_decimal -= p.first;
        }
    }

    //Allocate memory of len + 1 for termination character
    char* numeral = static_cast<char*>(::operator new(len + 1, std::nothrow));
    temp_decimal = decimal; // reset temp to it's original value

    int pos{0}; // used for the starting position of to copy the data

    //Copy the data to the block of memory numeral points to
    for(const std::pair<int, const char*> p: roman_vector)
    {
        while(temp_decimal >= p.first)
        {
            len = strlen(p.second);
            memcpy(numeral + pos, p.second, len);
            pos += len;
            temp_decimal -= p.first;
        }
    }
    numeral[pos] = '\0'; // add the terminating character at the end
    return numeral;
}

roman_int roman_int::operator=(const roman_int& other) noexcept
{
    if(this != &other)
    {
        decimal = other.decimal;
    }
    return *this;
}

roman_int& roman_int::operator+=(const roman_int& other) noexcept
{
    decimal += other.decimal;
    return *this;
}

roman_int& roman_int::operator-=(const roman_int& other) noexcept
{
    decimal -= other.decimal;
    return *this;
}

roman_int& roman_int::operator*=(const roman_int& other) noexcept
{
    decimal *= other.decimal;
    return *this;
}

roman_int& roman_int::operator/=(const roman_int& other) noexcept
{
    decimal /= other.decimal;
    return *this;
}

roman_int& roman_int::operator%=(const roman_int& other) noexcept
{
    decimal %= other.decimal;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const roman_int& r) noexcept
{
    return os << "Decimal: " << r.decimal;
}