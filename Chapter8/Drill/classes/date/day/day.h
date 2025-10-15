#pragma once
#include <ostream>

struct day
{
    int d;
};

std::ostream& operator<<(std::ostream& os, const day& day);

day& operator+(day& d, int& value);
day& operator+=(day& d, int& value);