#pragma once
#include <string>

class Variable
{
    public:
        double value;
        std::string name;

        Variable(std::string var, double val);
        ~Variable();
};