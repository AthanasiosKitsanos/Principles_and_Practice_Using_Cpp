#pragma once

#include <ostream>

struct year
{
    int y;
};

std::ostream& operator<<(std::ostream& os, const year& y);