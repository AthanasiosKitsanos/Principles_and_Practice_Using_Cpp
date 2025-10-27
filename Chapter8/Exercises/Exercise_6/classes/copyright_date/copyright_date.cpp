#include "copyright_date.h"
#include <cstring>
#include <cstdlib>

copyright_date::copyright_date(const short& y, const unsigned char& m, const unsigned char& d): year(y), month(m), day(d)
{
    if(!is_valid_date()) throw invalid{"Invalid date"};
}
copyright_date::~copyright_date() {}

bool copyright_date::is_valid_date()
{
    return (year > 1000 && year < 2026) && (month < 13 && month > 0) && (day > 0 && day < 32);
}

const int copyright_date::get_year() const { return year; }
const int copyright_date::get_month() const { return month; }
const int copyright_date::get_day() const { return day; }

copyright_date::invalid::invalid(const char* c)
{
    message = static_cast<char*>(malloc(std::strlen(c) + 1));
    if(message) std::strcpy(message, c);
}

copyright_date::invalid::~invalid()
{
    free(message);
}

const char* copyright_date::invalid::what() const noexcept
{
    return message;
}

std::ostream& operator<<(std::ostream& os, const copyright_date& date)
{
    return os << date.get_day() << '/' << date.get_month() << '/' << date.get_year();
}