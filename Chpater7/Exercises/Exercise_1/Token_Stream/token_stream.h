#pragma once
#include "token.h"
#include <istream>

class Variable;

class Token_Stream
{
    private:
        std::istream& stream;
        bool is_full;
        Token buffer;

    public:
        Token_Stream(std::istream& steam);
        ~Token_Stream();

        Token get();
        void putback(Token& token);
        void ignore(char c);
};  