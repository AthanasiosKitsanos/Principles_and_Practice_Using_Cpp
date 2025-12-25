#include "readings.h"

readings::readings(const double temp, const int h): temperature(temp), hour(h) {}
readings::~readings() {}

std::ostream& operator<<(std::ostream& os, const readings& r)
{
    return os << r.hour << '\t' << r.temperature;
}