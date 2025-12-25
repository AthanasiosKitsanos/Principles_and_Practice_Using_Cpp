#include "year.h"

std::ostream& operator<<(std::ostream& os, const year& y)
{
    return os << y.y;
}