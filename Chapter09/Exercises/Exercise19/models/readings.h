#pragma once
#include "pch.h"

class readings
{
    public:
        double temperature;
        int hour;
        char suffix;

        explicit readings();
        explicit readings(const double temp, const int h, const char suf);
        ~readings();

        bool is_valid_hour();
        bool is_valid_suffix();
        const char* error();
};

std::ostream& operator<<(std::ostream& os, const readings& r);