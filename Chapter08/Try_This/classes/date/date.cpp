#include "date.h"

date::date() {}

date::date(const year& yy, const month& mm, const int& dd):y(yy), m(mm), d(dd)
{
    if(!is_valid()) throw invalid{"Invalid Date"};
}

date::~date() {}

void date::add_day(const int& day)
{
    d += day;
}

bool date::is_valid()
{
    return 0 < to_int(m) && to_int(m) < 13;
}

std::ostream& operator<<(std::ostream& os, const date& d)
{
    return os << d.day() << '/' << d.get_month() << '/' << d.get_year();
}