#include "headers.h"
#include "token_stream.h"
#include "token.h"
#include "definitions.h"
#include "variable.h"
#include "global.h"
#include "functions.h"

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
            case _quit:
            case _print:
                return Token{ch}; // let each character represent itself

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

                    while(std::cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    {
                        s += ch;
                    }

                    std::cin.putback(ch);

                    for(const Variable& v: var_table)
                    {
                        if(v.name == s)
                        {
                            return Token{_number, v.value};
                        }
                    }

                    for(const Functions& f: func_table)
                    {
                        if(f.name == s)
                        {
                            return Token{_let, s};
                        }
                    }

                    if(s == "help") return Token{_h};

                    if(s == _clear) return Token{_c};

                    if(s == "quit") return Token{_quit};

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

double Token_Stream::get_value(std::string s)
{
    for(const Variable& v: var_table)
    {
        if(v.name == s)
        {
            return v.value;
        }
    }

    throw std::runtime_error("trying to read undefined variable " + s);
}

void Token_Stream::set_value(std::string s, double d)
{
    for(Variable& v: var_table)
    {
        if(v.name == s)
        {
            v.value = d;
            return;
        }
    }

    throw std::runtime_error("trying to write undefined variable " + s);
}

bool Token_Stream::is_declared(std::string var) // is var already in var_table?
{
    for(const Variable& v: var_table)
    {
        if(v.name == var)
        {
            return true;
        }
    }

    return false;
}

double Token_Stream::define_name(std::string var, double val) // add(var, val) to var_table
{
    if(is_declared(var))
    {
        throw std::runtime_error(var + " declared twice");
    }

    var_table.push_back(Variable{var, val});
    return val;
}

void Token_Stream::define_function(std::string name, Variable arg)
{
    if(is_defined(name))
    {
        throw std::runtime_error( name + arg.name + " function already exists");
    }

    func_table.push_back(Functions{name, arg});
}

bool Token_Stream::is_defined(std::string name)
{
    for(const Functions& f: func_table)
    {
        if(f.name == name)
        {
            return true;
        }
    }

    return false;
}

void Token_Stream::set_parameter(std::string name, double value)
{
    for(Functions& f: func_table)
    {
        if(f.name == name)
        {
            f.var.value = value;
            return;
        }
    }

    throw std::runtime_error("Trying to set an undefined parameter");
}