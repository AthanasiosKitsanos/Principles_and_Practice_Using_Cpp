#include "readings.h"

reading::reading(): temperature(-777), hour(-777) {} // -777 means it is just created
reading::~reading() {}

bool reading::is_valid_hour()
{
    return hour >= 0 && hour < 24;
}

const char* reading::error()
{
    return "Hour out of range\n";
}