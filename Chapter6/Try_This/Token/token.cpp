#include "headers.h"
#include "token.h"    
#include "token_stream.h"       

Token::Token() {}
Token::Token(char k):kind(k), value(0.00) {}
Token::Token(char k, double v):kind(k), value(v) {}
Token::Token(char k, std::string n): kind(k), name(n) {}
Token::~Token() {}



double Token::expression()
{
    double left = term();

    while(true)
    {
        Token t = ts_global->get();

        switch(t.kind)
        {
            case '+':
                left += term();
                break;

            case '-':
                left -= term();
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

    while(true)
    {
        Token t = ts_global->get();

        switch(t.kind)
        {
            case '*':
                left *= primary();
                break;

            case '/':
            {
                double d = primary();

                if(d == 0)
                {
                    throw std::invalid_argument("Division by zero is not allowed");
                }

                left /= d;
                break;
            }
            
            case '%':
            {
                // double d = primary();

                // if(d == 0)
                // {
                //     throw std::runtime_error("Division by zero not allowed");
                // }

                // left = std::fmod(left, d);


                //--------------or--------------
                int val1 = static_cast<int>(left);
                int val2 = static_cast<int>(primary());

                if(val2 == 0)
                {
                    throw std::runtime_error("Division by zero is not allows");
                }

                left = val1 % val2;

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
                throw std::invalid_argument("')' expected");
            }

            return d;
        }

        case '-':
            return - primary();

        case '+':
            return primary();

        case _KIND_IS_NUMBER:
            return t.value;

        default:
            throw std::invalid_argument("Expected a primary");
    }
}

double Token::statement()
{
    Token t = ts_global->get();
    
    switch(t.kind)
    {
        case _LET:
            return declaration();

        default:
            ts_global->putback(t);
            return t.expression();
    }
}

double Token::declaration()
{
    Token t1 = ts_global->get();

    if(t1.kind != _NAME)
    {
        throw std::runtime_error("name expected im declaration");
    }

    Token t2 = ts_global->get();

    if(t2.kind != '=')
    {
        throw std::runtime_error("= missing in declaration of " + t1.name);
    }

    double d = expression();

    define_name(t1.name, d);
    return d;
}