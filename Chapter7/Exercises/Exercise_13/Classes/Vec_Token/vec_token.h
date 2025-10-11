#pragma once

#include <string>

class vec_token
{
    std::string word;
    int length;

    public:
        vec_token(const std::string& w, const int& l);
        ~vec_token();

        void set_word(const std::string& w);
        void set_length(const int& l);
        std::string get_word();
        int get_length();
};