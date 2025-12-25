#pragma once
#include "token.h"

class Variable;

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
};  