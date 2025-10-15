#include "date.h"

date::date() {}
date::date(const year& yy):y(yy) {}

date::date(const day& dd):d(dd) { if(!is_valid_day()) throw invalid{"Invalid day"}; }
date::date(const month& mm):m(mm) { if(!is_valid_month()) throw invalid{"Invalid day"}; }
date::date(const year& yy, const month& mm): y(yy), m(mm) { if(!is_valid_month()) throw invalid{"Invalid month"}; }
date::date(const year& yy, const day& dd):y(yy), d(dd) { if(!is_valid_day()) throw invalid{"Invalid day"}; }
date::date(const month& mm, const day& dd)
{
    if(!is_valid_month()) throw invalid{"Invalid month"};
    if(!is_valid_day()) throw invalid{"Invalid day"};
}
date::date(const year& yy, const month& mm, const day& dd):y(yy), m(mm), d(dd)
{
    if(!is_valid_month()) throw invalid{"Invalid month"};
    if(!is_valid_day()) throw invalid{"Invalid day"};
}

date::~date() {}

void date::add_day(const int& day)
{
    d.d += day;
}

bool date::is_valid_month()
{
    return 0 < to_int(m) && to_int(m) < 13;
}

bool date::is_valid_day()
{
    return 0 < d.d && d.d < 31;
}

std::ostream& operator<<(std::ostream& os, const date& d)
{
    return os << d.get_day() << '/' << d.get_month() << '/' << d.get_year();
}