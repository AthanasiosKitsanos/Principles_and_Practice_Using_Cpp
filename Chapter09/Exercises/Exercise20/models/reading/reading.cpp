#include "reading.h"
#include "parser_context/parser_context.h"
#include "global.h"

reading::reading(const double& t): temperature(t), day(-1), hour(-1) {}
reading::reading(const double& t, const int d, const int h): temperature(t), day(d), hour(h) {}
reading::~reading() {}

bool reading::is_valid_day() { return day > 0 && day < 32; }
bool reading::is_valid_hour() { return hour > -1 && hour < 24; }
bool reading::is_implausible_temp() { return temperature >= imlausible_min && temperature <= imlausible_max; }

std::istream& operator>>(std::istream& is, reading& r)
{
    while(isspace(*global_pc->current)) ++global_pc->current;
    auto result = std::from_chars(global_pc->current, global_pc->end, r.day);
    if(result.ec != std::errc{})
    {
        is.clear(std::ios::failbit);
        std::cout << "Failed to read number of day\n";
        return is;
    }
    if(!r.is_valid_day())
    {
        is.clear(std::ios::failbit);
        std::cout << "Day out of range\n";
        return is;
    }
    global_pc->current = result.ptr;
    while(isspace(*global_pc->current)) ++global_pc->current;
    result = std::from_chars(global_pc->current, global_pc->end, r.hour);
    if(result.ec != std::errc{})
    {
        is.clear(std::ios::failbit);
        std::cout << "Failed to read hour\n";
        return is;
    }
    if(!r.is_valid_hour())
    {
        is.clear(std::ios::failbit);
        std::cout << "Hour is out of range\n";
        return is;
    }
    global_pc->current = result.ptr;
    while(isspace(*global_pc->current)) ++global_pc->current;
    result = std::from_chars(global_pc->current, global_pc->end, r.temperature);
    if(result.ec != std::errc{})
    {
        is.clear(std::ios::failbit);
        std::cout << "Failed to read temperature\n";
        return is;
    }
    if(!r.is_implausible_temp())
    {
        r.temperature = not_a_reading;
        is.clear(std::ios::failbit);
        std::cout << "Temperature our of range\n";
        return is;
    }
    global_pc->current = result.ptr;
    while(isspace(*global_pc->current)) ++global_pc->current;
    if(*global_pc->current == ')')
    {
        ++global_pc->current;
        while(isspace(*global_pc->current)) ++global_pc->current;
        return is;
    }
    r.temperature = not_a_reading;
    std::cout << "Reading needs to close with '}'\n";
    is.clear(std::ios::failbit);
    return is;
}

std::ostream& operator<<(std::ostream& os, const reading& r)
{
    if(r.temperature == not_a_reading) return os;
    return os << "( " << r.day << ' ' << r.hour << ' ' << r.temperature << " )"; 
}