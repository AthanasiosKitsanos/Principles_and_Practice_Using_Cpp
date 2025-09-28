#pragma once
#include <string>

class Variable
{
    public:
        double value;
        std::string name;
        bool is_const;
        
        Variable(std::string var, double val, bool is_c);
        ~Variable();
};