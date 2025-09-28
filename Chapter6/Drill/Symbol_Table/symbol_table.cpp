#include "symbol_table.h"

Symbol_Table::Symbol_Table() {}
Symbol_Table::~Symbol_Table() {}

double Symbol_Table::get_value(std::string s)
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

void Symbol_Table::set_value(std::string s, double d)
{
    for(Variable& v: var_table)
    {
        if(v.name == s)
        {   
            if(v.is_const)
            {
                throw std::runtime_error("The variable cannot be set, since it's a cinstant");
            }

            v.value = d;
            return;
        }
    }

    throw std::runtime_error("trying to write undefined variable " + s);
}

bool Symbol_Table::is_declared(std::string var) // is var already in var_table?
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

double Symbol_Table::define_name(std::string var, double val, bool is_const) // add(var, val) to var_table
{
    if(is_declared(var))
    {
        throw std::runtime_error(var + " declared twice");
    }

    var_table.push_back(Variable{var, val, is_const});
    return val;
}