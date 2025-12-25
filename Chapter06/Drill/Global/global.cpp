#include "global.h"
#include "token_stream.h"
#include "token.h"
#include "definitions.h"
#include "variable.h"

Token_Stream* ts_global = nullptr;
Symbol_Table sym_table = Symbol_Table{};

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
}

void clean_up_mess()
{
    ts_global->ignore(_print);
}

void show_variables()
{
    std::cout << "Variables:" << std::endl;
    for(int i = 0; i < sym_table.var_table.size() - 1; i += 2)
    {
        std::cout << (sym_table.var_table[i].is_const ? "const " : "") << sym_table.var_table[i].name << '(' << sym_table.var_table[i].value << "), ";
        std::cout << (sym_table.var_table[i + 1].is_const ? "const " : "") << sym_table.var_table[i + 1].name << '(' << sym_table.var_table[i + 1].value << ")";
    }

    if(sym_table.var_table.size() % 2 == 1)
    {
        std::cout << ", " << (sym_table.var_table[sym_table.var_table.size() - 1].is_const ? "const " : "") << sym_table.var_table[sym_table.var_table.size() - 1].name << '(' << sym_table.var_table[sym_table.var_table.size() - 1].value << ')';
    }

    std::cout << std::endl;
}

void calculate()
{
    while(std::cin)
    {
        try
        {
            std::cout << _prompt;

            Token t = ts_global->get();

            while(t.kind == _print)
            {
                t = ts_global->get();
            }

            if(t.kind == _h)
            {
                std::cout << std::endl;
                show_variables();

                t = ts_global->get();
                continue;
            }

            if(t.kind == _c)
            {
                system("cls");
                continue;
            }
            
            if(t.kind == _e)
            {
                break;
            }
            
            ts_global->putback(t);
            std::cout << _result << t.statement() <<std::endl;
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
            clean_up_mess();
        }
    }
}