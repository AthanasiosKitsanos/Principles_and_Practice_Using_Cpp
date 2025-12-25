#pragma once
#include "global.h"

class Token_Stream;

class Token
{
    private:
        static Token_Stream* ts;

    public:
        char kind;
        double value;

        Token();
        Token(char k);
        Token(char k, double v);

        double expression();
        double term();
        double primary();
        void set_to_global(Token_Stream* pointer);
};