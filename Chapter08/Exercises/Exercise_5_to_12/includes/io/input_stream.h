#pragma once
#include <string>
#include "../models/books.h"
#include "../models/token.h"

class input_stream
{
    char c;

    public:
        input_stream();
        ~input_stream();

        models::token get_command();
        std::string get_parameter();
        std::string await_string();
        short await_year();
        unsigned char await_m_or_d();
        models::genre await_genre();
        void clear_input();
};