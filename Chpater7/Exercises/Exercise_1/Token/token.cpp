#include "headers.h"
#include "token.h"    
#include "token_stream.h"       
#include "global.h"
#include "definitions.h"
#include "variable.h"

Token::Token() {}
Token::Token(char k):kind(k), value(0.00) {}
Token::Token(char k, double v): kind(k), value(v) {}
Token::Token(char k, std::string n): kind(k), name(n) {}
Token::Token(char k, std::string n, double v): kind(k), name(n), value(v) {}
Token::~Token() {}

double Token::statement(Token_Stream& ts)
{
    Token t = ts.get();

    switch(t.kind)
    {
        case _let:
            return declaration(ts);

        case _const:
            ts.putback(t);
            return declaration(ts);

        default:
            ts.putback(t);
            return expression(ts);
        
    }
}

double Token::declaration(Token_Stream& ts) // assume we have seen "let" // handle: name = expression // declare a variable called "name" with the initial value "expression"
{
    bool is_const = false;

    Token t = ts.get();

    if(t.kind == _const)
    {
        is_const = true;
        t = ts.get();
    }

    if(t.kind != _name)
    {
        throw std::runtime_error("name expected in declaration");
    }

    Token t2 = ts.get();
    
    switch(t2.kind)
    {
        case '=':
        {
            double d = expression(ts);
            sym_table.define_name(t.name, d, is_const);
            return d;
        }

        default:
            throw std::runtime_error("')' expected after function declaration");
    }
}

double Token::implement(Token_Stream& ts) // implements the variable again and returns it's new value
{
    Token t = ts.get();

    double d = expression(ts);
    
    sym_table.set_value(t.name, d);

    return d;
}

double Token::expression(Token_Stream& ts)
{
    double left = term(ts);

    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term(ts);
                t = ts.get();
                break;

            case '-':
                left -= term(ts);
                t = ts.get();
                break;

            default:
                ts.putback(t);
                return left;
        }
    }

    return left;
}

double Token::term(Token_Stream& ts)
{
    double left = primary(ts);

    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= primary(ts);
                t = ts.get();
                break;

            case '/':
            {
                double d = primary(ts);

                if(d == 0)
                {
                    throw std::runtime_error("Division by zero is not allowed");
                }

                left /= d;
                t = ts.get();
                break;
            }

            case '%':
            {
                double d = primary(ts);

                if(d == 0)
                {
                    throw std::runtime_error("%: division by 0");
                }

                left = std::fmod(left, d);
                t = ts.get();
                break;
            }

            default:
                ts.putback(t);
                return left;
        }
    }
}

double Token::primary(Token_Stream& ts)
{
    Token t = ts.get();

    switch(t.kind)
    {
        case '(':
        {
            double d = expression(ts);

            t = ts.get();

            if(t.kind == ',') // if () has 2 parameters inside
            {
                ts.putback(t);
                return d;
            }

            if(t.kind != ')')
            {
                throw std::runtime_error("')' expected");
            }

            return d;
        }

        case '-':
            return - primary(ts);

        case '+':
            return + primary(ts);

        case _number:
            return t.value;

        case _f: // case it is a function
        {
            if(t.name == "sqrt") // chaecking for sqrt
            {
                double d = expression(ts);

                if(d < 0) // checking in case the number is less than zero
                {
                    throw std::runtime_error("Getting square root of negative number");
                }

                return sqrt(d);
            }

            if(t.name == "pow") // getting the pow
            {
                double d = expression(ts);

                t = ts.get();

                if(t.kind != ',')
                {
                    throw std::runtime_error("expected ',' after first parameter");
                }

                int multiplier = static_cast<int>(expression(ts));

                t = ts.get();

                if(t.kind != ')')
                {
                    ts.putback(t);
                    throw std::runtime_error("expected ')' after second parameter");
                }

                return pow(d, multiplier);
            }
        }

        case _name:
        {
            Token t2 = ts.get();

            if(t2.kind == '=') // if true implements the variable again 
            {
                return implement(ts);
            }

            ts.putback(t2);
            return sym_table.get_value(t.name);
        }

        default:
            throw std::runtime_error("Expected a primary");
    }
}