#include "headers.h"
#include "token.h"    
#include "token_stream.h"       
#include "global.h"
#include "definitions.h"

Token::Token() {}
Token::Token(char k):kind(k), value(0.00) {}
Token::Token(char k, double v): kind(k), value(v) {}
Token::Token(char k, std::string n): kind(k), name(n) {}
Token::~Token() {}

double Token::statement()
{
    Token t = ts_global->get();

    switch(t.kind)
    {
        case _let:
            return declaration();

        default:
            ts_global->putback(t);
            return expression();
    }
}

double Token::declaration() // assume we have seen "let" // handle: name = expression // declare a variable called "name" with the initial value "expression"
{
    Token t = ts_global->get();

    if(t.kind != _name)
    {
        throw std::runtime_error("name expected in declaration");
    }

    Token t2 = ts_global->get();

    if(t2.kind != '=')
    {
        throw std::runtime_error("= is missing in declaration of " + t.name);
    }

    double d = expression();

    ts_global->define_name(t.name, d);
    return d;
}

double Token::expression()
{
    double left = term();

    Token t = ts_global->get();

    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term();
                t = ts_global->get();
                break;

            case '-':
                left -= term();
                t = ts_global->get();
                break;

            default:
                ts_global->putback(t);
                return left;
        }
    }

    return left;
}

double Token::term()
{
    double left = primary();

    Token t = ts_global->get();

    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= primary();
                t = ts_global->get();
                break;

            case '/':
            {
                double d = primary();

                if(d == 0)
                {
                    throw std::runtime_error("Division by zero is not allowed");
                }

                left /= d;
                t = ts_global->get();
                break;
            }

            case '%':
            {
                double d = primary();

                if(d == 0)
                {
                    throw std::runtime_error("%: division by 0");
                }

                left = std::fmod(left, d);
                t = ts_global->get();
                break;
            }

            default:
                ts_global->putback(t);
                return left;
        }
    }
}

double Token::primary()
{
    Token t = ts_global->get();

    switch(t.kind)
    {
        case '(':
        {
            double d = expression();

            t = ts_global->get();

            if(t.kind != ')')
            {
                throw std::runtime_error("')' expected");
            }

            return d;
        }

        case '-':
            return - primary();

        case '+':
            return + primary();

        case _number:
            return t.value;

        default:
            throw std::runtime_error("Expected a primary");
    }
}