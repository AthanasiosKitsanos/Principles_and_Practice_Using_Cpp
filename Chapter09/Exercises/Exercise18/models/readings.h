#pragma once
#include "pch.h"

class readings
{
    public:
        double temperature;
        int hour;

        explicit readings(const double temp, const int h);
        ~readings();
};

std::ostream& operator<<(std::ostream& os, const readings& r);