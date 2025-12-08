#pragma once
#include "month/month.h"

struct year
{
    std::vector<month> months;
    int y;

    year();
    ~year();
};

std::istream& operator>>(std::istream& is, year& y);
std::ostream& operator<<(std::ostream& os, const year& y);