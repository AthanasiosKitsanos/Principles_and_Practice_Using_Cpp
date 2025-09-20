#include "headers.h"
#include "token.h"    
#include "token_stream.h"
#include "global.h"

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
        case '{': // added the ability to use {}
            {
                double d = expression();

                t = ts->get();
                
                if(t.kind != '}')
                {
                    throw std::invalid_argument("'}' expected");
                }

                return d;
            }

        case _KIND_IS_NUMBER:
            {
                Token next = ts->get();

                if(next.kind == '!')
                {   
                    if(t.value != int(t.value))
                    {
                        throw std::runtime_error("Trying a factorial of a non-integer");
                    }

                    if(t.value < 0)
                    {
                        throw std::runtime_error("No factorial for negative numbers");
                    }
                    else if(t.value == 0)
                    {
                        return 1;
                    }

                    int result = 1;

                    for(int i = 1; i <= int(t.value); i++)
                    {
                        result *= i;
                    }

                    return result;
                }

                ts->putback(next);
            
                return t.value;
            }

        default:
            throw std::invalid_argument("Expected a primary");
    }
}

void Token::initializa_token_pointer(Token_Stream* ptr)
{
    ts = ptr;
}

void Token::delete_token_pointer()
{
    ts = nullptr;
}