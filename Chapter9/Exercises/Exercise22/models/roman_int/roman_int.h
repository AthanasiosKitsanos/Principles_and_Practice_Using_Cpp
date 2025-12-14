#pragma once

#include <iostream>
#include <vector>

inline std::vector<std::pair<int, const char*>> roman_vector
{
    {1000, "M"}, {900, "CM"}, {500, "D"},
    {400, "CD"}, {100, "C"}, {90, "XC"},
    {50 , "L"}, {40, "XL"}, {10, "X"},
    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

struct roman_int
{
    //Variables
    int decimal;
    bool is_valid;
    
    //Constructors
    explicit roman_int();
    explicit roman_int(const int value);
    roman_int(const roman_int& other);
    ~roman_int();
    
    //Operators
    roman_int operator=(const roman_int& other) noexcept;
    roman_int& operator+=(const roman_int& other) noexcept;
    roman_int& operator-=(const roman_int& other) noexcept;
    roman_int& operator*=(const roman_int& other) noexcept;
    roman_int& operator/=(const roman_int& other) noexcept;
    roman_int& operator%=(const roman_int& other) noexcept;

    //Functions
    char* decimal_to_roman() const noexcept;
};

std::ostream& operator<<(std::ostream& os, const roman_int& r) noexcept;