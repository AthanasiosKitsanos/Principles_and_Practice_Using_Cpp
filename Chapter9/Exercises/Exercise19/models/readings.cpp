#include "readings.h"

readings::readings() {}
readings::readings(const double temp, const int h, const char suf): temperature(temp), hour(h), suffix(suf) {}
readings::~readings() {}

bool readings::is_valid_hour()
{
    return hour >= 0 && hour < 24;
}

const char* readings::error()
{
    return "Hour out of range or wrong suffix\n";
}

bool readings::is_valid_suffix()
{
    return suffix == 'c' || suffix == 'f';
}

std::ostream& operator<<(std::ostream& os, const readings& r)
{
    return os << r.hour << '\t' << r.temperature;
}