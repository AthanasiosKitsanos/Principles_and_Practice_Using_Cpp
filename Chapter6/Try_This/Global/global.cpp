#include "headers.h"
#include "global.h"
#include "token_stream.h"
#include "token.h"
#include "variable.h"

Token_Stream* ts_global = nullptr;
std::vector<Variable> var_table;

void initialize_stream_pointer()
{
    void* raw_memory = _aligned_malloc(sizeof(Token_Stream), alignof(Token_Stream));
    if(!raw_memory)
    {
        throw std::runtime_error("Failed to allocate Token_Stream");
    }

    ts_global = new(raw_memory) Token_Stream();
}

void delete_stream_pointer()
{
    if(ts_global)
    {
        ts_global->~Token_Stream();
        _aligned_free(ts_global);
        ts_global = nullptr;
    }

    std::cin.clear();
    std::cout << "Press any key to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void calculate()
{
    while(std::cin)
    {
        try
        {
            std::cout << _PROMPT;

            Token t = ts_global->get();
            
            while(t.kind == _PRINT)
            {
                t = ts_global->get();
            }

            if(t.kind == _QUIT)
            {
                break;
            }
            
            ts_global->putback(t);
            std::cout << _RESULT << t.statement() << std::endl;
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
            clean_up_mess();
        }
        catch(std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
            clean_up_mess();
        }
    }
}

void clean_up_mess()
{
    ts_global->ignore(_PRINT);
}

void set_value(std::string s, double d)
{
    for(Variable& v: var_table)
    {
        if(v.name == s)
        {
            v.value = d;
            return;
        }
    }

    throw std::runtime_error("Trying to write undefined variable" + s);
}

double get_value(std::string s)
{
    for(const Variable& v: var_table)
    {
        if(v.name == s)
        {
            return v.value;
        }
    }

    throw std::runtime_error("Trying to read undefined variable " + s);
}

bool is_declared(std::string s)
{
    for(const Variable& v: var_table)
    {
        if(v.name == s)
        {
            return true;
        }
    }

    return false;
}

double define_name(std::string var, double val)
{
    if(is_declared(var))
    {
        throw std::runtime_error("Variable already declare");
    }

    var_table.push_back(Variable{var, val});

    return val;
}