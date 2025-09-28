#pragma once
#include "headers.h"
#include "variable.h"

class Variable;

class Symbol_Table
{
    public:
        Symbol_Table();
        ~Symbol_Table();
        
        std::vector<Variable> var_table;

        double get_value(std::string s);
        void set_value(std::string s, double d);

        bool is_declared(std::string var);
        double define_name(std::string var, double val, bool is_const);
};