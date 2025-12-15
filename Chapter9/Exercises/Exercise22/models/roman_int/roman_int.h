#pragma once

#include <iostream>
#include <vector>

// Vector used for the int convertion to Roman Numeral
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
    int decimal; // stores an int
    bool is_valid; // flag that shows if the instance is in a valid state
    
    //Constructors
    explicit roman_int();
    explicit roman_int(const bool valid);
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