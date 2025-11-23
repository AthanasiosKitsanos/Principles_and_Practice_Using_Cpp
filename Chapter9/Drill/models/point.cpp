#include "pch.h"
#include "point.h"
#include <charconv>

point::point(): x(0.0), y(0.0), is_valid(false) {}
point::~point() {}

void point::reset()
{
    x = 0.0;
    y = 0.0;
}

void point::invalid()
{
    x = -1.0;
    y = -1.0;
    std::cout << "Invalid entry\n" << std::flush;
}

bool point::operator==(const point& other) const
{
    return x == other.x && y == other.y;
}

bool point::operator!=(const point& other) const
{
    return x != other.x || y != other.y;
}

std::ostream& operator<<(std::ostream& os, const std::vector<point>& vec)
{
    size_t i{0};
    for(; i < vec.size() - 1; ++i)
    {
        os << vec[i] << '\n';
    }
    os << vec[vec.size() - 1];
    return os;
}

std::ostream& operator<<(std::ostream& os, const point& p)
{
    if(!p.is_valid)
    {
        return os << "Invalid" << '(' << p.x << "," << p.y << ')';
    }
    return os << '(' << p.x << "," << p.y << ')';
}

std::istream& operator>>(std::istream& is, point& p)
{
    p.reset();
    char buffer[16];
    is.getline(buffer, sizeof(buffer));
    const char* current_index = buffer;
    const char* end = buffer + std::strlen(buffer);
    while(current_index < end && isspace(*current_index)) ++current_index;
    if(current_index >= end || *current_index != '(') 
    {
        p.invalid();
        return is;
    }
    auto [x_ptr, ec] = std::from_chars(++current_index, end, p.x);
    if(ec != std::errc{})
    { 
        p.invalid();
        return is;
    }
    current_index = x_ptr;
    if(current_index >= end || *current_index != ',')
    {
        p.invalid();
        return is;
    }
    auto [y_ptr, ec2] = std::from_chars(++current_index, end, p.y);
    if(ec2 != std::errc{})
    {
        p.invalid();
        return is;
    }
    current_index = y_ptr;
    if(current_index >= end || *current_index != ')')
    {
        p.invalid();
        return is;
    }
    if(*(++current_index) != '\0' && !isspace(*current_index))
    {
        p.invalid();
        return is;
    }
    p.is_valid = true;
    return is;   
}