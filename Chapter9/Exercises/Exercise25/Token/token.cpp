#include "headers.h"
#include "token.h"    
#include "token_stream.h"       
#include "global.h"
#include "definitions.h"
#include "variable.h"
#include <fstream>

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
        case _let:
            return declaration();

        case _const:
            ts_global->putback(t);
            return declaration();

        default:
            ts_global->putback(t);
            return expression();
        
    }
}

double Token::declaration() // assume we have seen "let" // handle: name = expression // declare a variable called "name" with the initial value "expression"
{
    bool is_const = false;

    Token t = ts_global->get();

    if(t.kind == _const)
    {
        is_const = true;
        t = ts_global->get();
    }

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
            sym_table.define_name(t.name, d, is_const);
            return d;
        }

        default:
            throw std::runtime_error("')' expected after function declaration");
    }
}

double Token::implement(Token t) // implements the variable again and returns it's new value
{
    double d = expression();
    
    sym_table.set_value(t.name, d);

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

            if(t.kind == ',') // if () has 2 parameters inside
            {
                ts_global->putback(t);
                return d;
            }

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

        case _f: // case it is a function
        {
            if(t.name == "sqrt") // chaecking for sqrt
            {
                double d = expression();

                if(d < 0) // checking in case the number is less than zero
                {
                    throw std::runtime_error("Getting square root of negative number");
                }

                return sqrt(d);
            }

            if(t.name == "pow") // getting the pow
            {
                double d = expression();

                t = ts_global->get();

                if(t.kind != ',')
                {
                    throw std::runtime_error("expected ',' after first parameter");
                }

                int multiplier = static_cast<int>(expression());

                t = ts_global->get();

                if(t.kind != ')')
                {
                    ts_global->putback(t);
                    throw std::runtime_error("expected ')' after second parameter");
                }

                return pow(d, multiplier);
            }
        }

        case _ifile:
        {
            //from example.txt to output.txt
            t = ts_global->get();
            std::ifstream ifs{t.name};
            if(!ifs) throw std::runtime_error{"Failed to open file"};
            t = ts_global->get();
            if(t.kind != _ofile) throw std::runtime_error{"Need to specify file output using 'to + file_name'"};
            std::streambuf* original_buffer = std::cin.rdbuf(); // save the original buffer of std::cin
            t = ts_global->get();
            std::ofstream ofs{t.name, std::ios::app}; // append each expression to the file to check all the tests
            std::getline(ifs, t.name); // reuse the t.name to avoid allocation for a new std::string
            ifs.seekg(0, std::ios::beg); // return the file pointer to the beginning of the file
            std::cin.rdbuf(ifs.rdbuf()); // make std::cin read from the file's buffer so the ts_global->get() works
            try
            {
                double d = expression(); // now std::cin will read the expression in the file
                ofs << "Example 1: " << t.name << " = " << d << '\n'; // print the result in the output file
                std::cin.rdbuf(original_buffer); // reset std::cin to read from the keyboard
                return d; // return the result to the console too
            }
            catch(const std::runtime_error& e)
            {
                ofs << "Example 1: " << t.name << " = " << e.what() << '\n'; // print the error to the output file
                std::cin.rdbuf(original_buffer); // reset std::cin to read from the keyboard
                throw std::runtime_error{e.what()}; // throw the error to the console too
            }
        }
        case _name:
        {
            Token t2 = ts_global->get();

            if(t2.kind == '=') // if true implements the variable again 
            {
                return implement(t);
            }

            ts_global->putback(t2);
            return sym_table.get_value(t.name);
        }
        default:
            throw std::runtime_error("Expected a primary");
    }
}