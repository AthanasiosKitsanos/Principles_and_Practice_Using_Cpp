#pragma once

#include <iostream>

struct roman_int
{
    std::string roman_numeral;

    explicit roman_int();
    ~roman_int();

    int as_int() const noexcept;
    int get_decimal_value(char c) const noexcept;
    bool is_valid_roman_entry(char c) const noexcept;
};

std::istream& operator>>(std::istream& is, roman_int& ri);
std::ostream& operator<<(std::ostream& os, const roman_int& ri) noexcept;