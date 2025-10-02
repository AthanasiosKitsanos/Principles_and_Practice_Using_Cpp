#include "global.h"
#include "token_stream.h"
#include "token.h"
#include "definitions.h"
#include "variable.h"

Token_Stream ts_global = Token_Stream{std::cin};
Symbol_Table sym_table = Symbol_Table{};

void clean_up_mess(Token_Stream ts)
{
    ts.ignore(_print);
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

void calculate(Token_Stream& ts)
{
    while(std::cin)
    {
        try
        {
            std::cout << _prompt;

            Token t = ts.get();

            while(t.kind == _print)
            {
                t = ts.get();
            }

            if(t.kind == _h)
            {
                std::cout << std::endl;
                show_variables();

                t = ts.get();
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
            
            ts.putback(t);
            std::cout << _result << t.statement(ts_global) <<std::endl;
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
            clean_up_mess(ts_global);
        }
    }
}