#include "roman_int.h"
#include <cstring>

roman_int::roman_int(): decimal(0), is_valid(true) {}

roman_int::roman_int(const int value): decimal(value), is_valid(true) {}

roman_int::roman_int(const roman_int& other): decimal(other.decimal), is_valid(other.is_valid) {}

roman_int::~roman_int() {}

char* roman_int::decimal_to_roman() const noexcept
{
    if(!is_valid) return nullptr;
    // {
    //     char* numeral = static_cast<char*>(::operator new(1));
    //     numeral[0] = '\0';
    //     return numeral;
    // }
    char temp_buffer[20];
    size_t len{0};
    int temp_decimal{decimal};
    int pos{0};
    for(const std::pair<int, const char*> p: roman_vector)
    {
        while(temp_decimal >= p.first)
        {
            len = strlen(p.second);
            memcpy(temp_buffer + pos, p.second, len);
            pos += static_cast<int>(len);
            temp_decimal -= p.first;
        }
    }
    temp_buffer[pos] = '\0';
    char* numeral = static_cast<char*>(::operator new(pos + 1));
    for(int i{0}; i < pos; ++i)
    {
        numeral[i] = temp_buffer[i];
    }
    numeral[pos] = '\0';
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
    if(!r.is_valid) return os;
    return os << "Decimal: " << r.decimal;
}