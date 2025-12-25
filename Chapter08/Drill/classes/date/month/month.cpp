#include "month.h"
#include "date.h"

std::vector<std::string> month_tbl =
{
    "Not a Month", "January", "February", "March",
    "Aplril", "May", "June", "July", "August",
    "September", "October", "November", "December"
};

month int_to_month(const int& x)
{
    if(x < to_int(month::jan) || x > to_int(month::dec)) throw date::invalid{"Bad Month"};
    return month{x};
}

int to_int(const month& m)
{
    return static_cast<int>(m);
}

std::ostream& operator<<(std::ostream& os, const month& m)
{
    return os << month_tbl[to_int(m)];
}

month operator++(month& m)
{
    m = (m == month::dec) ? month::jan : month{to_int(m) + 1};
    return m;
}