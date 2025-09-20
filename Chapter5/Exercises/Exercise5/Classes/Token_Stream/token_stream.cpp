#include "headers.h"
#include "token_stream.h"

Token_Stream::Token_Stream():is_full(false) {}
Token_Stream::~Token_Stream() {}

Token Token_Stream::get()
{
    if(is_full)
    {
        is_full = false;
        return buffer;
    }

    char c;
    std::cin >> c;

    switch(c)
    {
        case '~': case '^': case '&': case '|': case 'q': case ';': case '(': case ')': case '!':
            return Token{c};

        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            {
                std::cin.putback(c);
                int val = 0;
                std::cin >> val;

                return Token{'8', val};
            }

        default:
            throw std::runtime_error("Wrong input");
    }
}

void Token_Stream::putback(Token& token)
{
    if(is_full)
    {
        throw std::runtime_error("Buffer is full");
    }

    is_full = true;
    buffer = token;
}