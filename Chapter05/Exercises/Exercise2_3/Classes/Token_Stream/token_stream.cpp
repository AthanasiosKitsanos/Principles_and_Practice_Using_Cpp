#include "headers.h"
#include "token_stream.h"
#include "token.h"

Token_Stream::Token_Stream():buffer(Token{}), is_full(false) {}
Token_Stream::~Token_Stream() {}

Token Token_Stream::get()
{
    if(is_full)
    {
        is_full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;
    switch (ch)
    {
        case '(': case ')': case '+': case '-': case '*': case '/': case 'q': case ';': case '\n': case '{': case '}':
        case '!': // added the ability to use {} and factorial
            return Token{ch};


        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {
                std::cin.putback(ch);
                double val;
                std::cin >> val;

                return Token(_KIND_IS_NUMBER, val);
            }

        default:
            throw std::invalid_argument("Wrong input");
    }
}

void Token_Stream::putback(Token& token)
{
    if(is_full)
    {
        throw std::runtime_error("Budder is full");
    }

    buffer = token;
    is_full = true;
}