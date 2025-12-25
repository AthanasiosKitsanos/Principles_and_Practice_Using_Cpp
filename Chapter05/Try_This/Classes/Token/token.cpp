#include "headers.h"
#include "token.h"    
#include "token_stream.h"       

Token_Stream* Token::ts = ts_global;

Token::Token() {}

Token::Token(char k):kind(k), value(0.00) {}

Token::Token(char k, double v):kind(k), value(v) {}

double Token::expression()
{
    double left = term();

    Token t = ts->get();

    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term();
                t = ts->get();
                break;

            case '-':
                left -= term();
                t = ts->get();
                break;

            default:
                ts->putback(t);
                return left;
        }
    }

    return left;
}

double Token::term()
{
    double left = primary();

    Token t = ts->get();

    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= primary();
                t = ts->get();
                break;

            case '/':
                {
                    double d = primary();

                    if(d == 0)
                    {
                        throw std::invalid_argument("Division by zero is not allowed");
                    }

                    left /= d;
                    t = ts->get();
                    break;
                }

            default:
                ts->putback(t);
                return left;
        }
    }
}

double Token::primary()
{
    Token t = ts->get();

    switch(t.kind)
    {
        case '(':
            {
                double d = expression();

                t = ts->get();

                if(t.kind != ')')
                {
                    throw std::invalid_argument("')' expected");
                }

                return d;
            }

        case _KIND_IS_NUMBER:
            return t.value;

        default:
            throw std::invalid_argument("Expected a primary");
    }
}