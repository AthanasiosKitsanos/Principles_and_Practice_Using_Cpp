#include "headers.h"
#include "token_stream.h"
#include "token.h"

Token_Stream::Token_Stream() {}
Token_Stream::~Token_Stream() {}

Token Token_Stream::buffer = Token();
bool Token_Stream::is_full = false;

bool Token_Stream::is_alpha(char c)
{
    return true;
}

bool Token_Stream::is_digit(char c)
{
    return true;
}

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
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case _QUIT:
        case _PRINT:
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
            return Token{_KIND_IS_NUMBER, val};
        }

        default:
            if(is_alpha(ch))
            {
                std::string s;
                s += ch;

                while(std::cin.get(ch) && (is_alpha(ch) || is_digit(ch)))
                {
                    s += ch;
                }

                if(s == _DECL_KEY)
                {
                    return Token{_LET};
                }

                return Token{_NAME, s};
            }

            throw std::runtime_error("Bad Token");
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

void Token_Stream::ignore(char c)
{
    is_full = false;

    if(is_full && c == buffer.kind)
    {
        return;
    }

    char ch = 0;

    while(std::cin >> ch)
    {
        if(ch == c)
        {
            return;
        }
    }
}