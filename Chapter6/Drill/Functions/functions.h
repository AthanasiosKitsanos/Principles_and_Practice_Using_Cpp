#pragma once
#include "variable.h"

class Functions
{
    public:
        Variable var;
        std::string name;

        Functions(std::string n, Variable v);
        ~Functions();


};