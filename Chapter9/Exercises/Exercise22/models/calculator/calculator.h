#pragma once
#include <iostream>

class stream_pointer;
class roman_int;

class roman_calculator
{
    std::string input;
    stream_pointer* sp;
    char* r_numeral;
    short repeat;
    
    roman_int expression();
    roman_int term();
    roman_int primary();

    void free_r_numeral();

    public:
        roman_calculator();
        ~roman_calculator();

        void initialize_stream();
        void run();
};