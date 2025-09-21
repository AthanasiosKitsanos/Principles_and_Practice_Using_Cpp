#pragma once
#include "global.h"

class Token_Stream;

class Token
{
    public:
        double value;
        std::string name;
        char kind;

        Token();
        Token(char k);
        Token(char k, double v);
        Token(char k, std::string n);
        ~Token();

        double expression();
        double term();
        double primary();
        double statement();
        double declaration();
};