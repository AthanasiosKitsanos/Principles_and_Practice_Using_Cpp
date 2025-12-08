#include "roman_int.h"

roman_int::roman_int(): roman_numeral(""), is_valid_state(true) {}

roman_int::~roman_int() {}

int roman_int::get_decimal_value(char c) const noexcept
{
    switch(c)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return -1;
}

int roman_int::as_int() const noexcept
{
    if(roman_numeral.empty()) return -1;
    int number{get_decimal_value(roman_numeral[0])};
    for(size_t i {0}; i < roman_numeral.size() - 1; ++i)
    {
        if(number == get_decimal_value(roman_numeral[i + 1]) || number > get_decimal_value(roman_numeral[i + 1]))
        {
            number += get_decimal_value(roman_numeral[i + 1]);
            continue;
        }
        number = get_decimal_value(roman_numeral[i + 1]) - number;
    }
    return number;
}

bool roman_int::is_valid_roman_entry(char c) const noexcept
{
    switch(c)
    {
        case 'I': case 'V': case 'X':
        case 'L': case 'C': case 'D': case 'M':
            return true;
    }
    return false;
}

std::istream& operator>>(std::istream& is, roman_int& ri)
{
    std::getline(is, ri.roman_numeral);
    for(char& c: ri.roman_numeral)
    {
        if(isspace(c)) continue;;
        c = std::toupper(c);
        if(!ri.is_valid_roman_entry(c))
        {
            std::cout << "Invalid numeral: " << c << '\n';
            ri.roman_numeral.clear();
            return is;
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const roman_int& ri) noexcept
{
    return os << ri.roman_numeral;
}