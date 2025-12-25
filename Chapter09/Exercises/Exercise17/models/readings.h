#pragma once
#include "pch.h"

class reading
{
    public:
        double temperature;
        int hour;
        
        reading();
        ~reading();

        bool is_valid_hour();
        const char* error();
};