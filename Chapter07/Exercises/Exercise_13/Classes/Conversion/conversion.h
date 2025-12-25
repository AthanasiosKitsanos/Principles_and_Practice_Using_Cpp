#pragma once
#include <vector>
#include <iostream>

class vec_token;

class vector_conversion
{
    bool sorted;

    public:
        vector_conversion();
        ~vector_conversion();

        std::vector<std::string> string_vector;

        vec_token get_greatest_length();
        vec_token get_smallest_length();

        void get_string_length();
        void print_min_and_max_length();
        void print_smallest_and_biggest_word();

        template<typename Ret, typename... Args>
        void run_loop_for(Ret(vector_conversion::*func)(Args...));
};

#include "conversion.tpp"