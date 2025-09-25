#include "headers.h"
#include "token.h"    
#include "token_stream.h"       
#include "global.h"
#include "definitions.h"
#include "functions.h"
#include "variable.h"

Token::Token() {}
Token::Token(char k):kind(k), value(0.00) {}
Token::Token(char k, double v): kind(k), value(v) {}
Token::Token(char k, std::string n): kind(k), name(n) {}
Token::Token(char k, std::string n, double v): kind(k), name(n), value(v) {}
Token::~Token() {}

double Token::statement()
{
    Token t = ts_global->get();

    switch(t.kind)
    {
        case _let: case _f: // added if a function is declared
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
    
    switch(t2.kind)
    {
        case '=':
        {
            double d = expression();
            ts_global->define_name(t.name, d);
            return d;
        }

        case '(':
        {
            double d = statement();
            
            ts_global->define_function(t.name, Variable{t.name, d});
            
            return 0;
        }

        case ')':
            return 0;

        default:
            throw std::runtime_error("')' expected after function declaration");
    }

    return 1;
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

        case _f:
        {
            ts_global->set_parameter(t.name, primary());


        }
            
        case _let:
        {
            double d = ts_global->get_value(t.name);
            return d;
        }

        default:
            throw std::runtime_error("Expected a primary");
    }
}