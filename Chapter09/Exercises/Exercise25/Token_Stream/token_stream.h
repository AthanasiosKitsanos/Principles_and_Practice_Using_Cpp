#pragma once
#include "token.h"

class Variable;

class Token_Stream
{
    private:
        Token buffer;
        bool is_full;

    public:
        Token_Stream();
        ~Token_Stream();

        Token get();
        void putback(Token& token);
        void ignore(char c);
};  