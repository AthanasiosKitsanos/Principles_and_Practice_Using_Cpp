#pragma once
#include "reading/reading.h"
#include "../global/global.h"

constexpr int not_a_month = -1;

struct month
{
    std::vector<reading> readings;
    std::vector<std::string> months_names = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };   
    int m;

    month(const int m);
    ~month();
};

std::istream& operator>>(std::istream& is, month& m);
std::ostream& operator<<(std::ostream& os, const month& m);