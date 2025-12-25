#include "headers.h"
#include "token_stream.h"
#include "token.h"
#include "definitions.h"
#include "variable.h"
#include "global.h"

Token_Stream::Token_Stream():is_full(false), buffer(Token{}) {}
Token_Stream::~Token_Stream() {}

Token Token_Stream::get() // reads characters from cin and compose a Token
{
    if(is_full) // checks if we already have a Token ready
    {
        is_full = false;
        return buffer;
    }

    char ch; //note that >> skips whitespaces (space, newline, tab, etc.)

    while(true)
    {
        std::cin.get(ch);

        switch (ch)
        {
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
            case ',':
            case _print:
                return Token{ch}; // let each character represent itself

            case '#':
                return Token{_let}; // added the new declaration key

            case ' ':
                break;

            case '.': // floating-point-literal can start with a dot
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': // numeric literal
            {
                std::cin.putback(ch); // put digit back into the input stream
                double val;
                std::cin >> val; // reading a floating-point number
                return Token{_number, val};
            }

            default:
                if(isalpha(ch))
                {
                    std::cin.putback(ch);

                    std::string s;

                    while(std::cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) // allowing underscores in variabale names
                    {
                        s += ch;
                    }

                    std::cin.putback(ch);

                    if(s == "const") return Token{_const};
                    if(s == "help") return Token{_h};
                    if(s == _clear) return Token{_c};

                    if(s == _exit) return Token{_e}; // changed it for _quit to _exit

                    if(s == "print") return Token{_print};

                    if(s == _declkey) return Token{_let}; // declaration keyword

                    if(s == _func_key) return Token{_f}; // function keyword

                    return Token{_name, s};
                }
        }
    }

    throw std::runtime_error("Wrong input");
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

void Token_Stream::ignore(char c) // c represents the kind of Token
{
    if(is_full && c == buffer.kind)
    {
        is_full = false;
        return;
    }

    is_full = false;

    char ch = 0;
    while(std::cin.get(ch))
    {
        if(ch == c)
        {
            return;
        }
    }
}