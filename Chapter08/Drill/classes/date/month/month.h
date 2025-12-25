#pragma once
#include <vector>
#include <string>

extern std::vector<std::string> month_tbl;

enum class month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
month int_to_month(const int& x);
int to_int(const month& m);
std::ostream& operator<<(std::ostream& os, const month& m);
month operator++(month& m);