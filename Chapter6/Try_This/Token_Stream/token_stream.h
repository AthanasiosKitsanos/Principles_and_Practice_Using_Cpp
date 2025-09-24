#pragma once
#include "token.h"

class Token_Stream
{
    private:
        bool is_full;
        Token buffer;

    public:
        Token_Stream();
        ~Token_Stream();

        Token get();
        void putback(Token& token);
        void ignore(char c);
        double get_value(std::string s);
        void set_value(std::string s, double d);
        bool is_declared(std::string var);
        double define_name(std::string var, double val);
};