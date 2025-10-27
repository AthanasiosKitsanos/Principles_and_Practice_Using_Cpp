#pragma once
#include <string_view>

struct i_stream
{   
    i_stream();
    ~i_stream();

    void clear_buffer(char& c);
    std::string get_input(char& c);
    short get_short(char& c);
    unsigned char get_usinged_char(char& c);
};