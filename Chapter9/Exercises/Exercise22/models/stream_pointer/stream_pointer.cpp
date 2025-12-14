#include "stream_pointer.h"

stream_pointer::stream_pointer(): start(nullptr) {}
stream_pointer::~stream_pointer()
{
    if(start) start = nullptr;
}

bool stream_pointer::is_valid_r_numeral(const char c) noexcept
{
    switch(c)
    {
        case 'I': case 'V': case 'X': case 'i': case 'v': case 'x':
        case 'L': case 'C': case 'D': case 'M': case 'l': case 'c': case 'd': case 'm':
            return true;
    }
    return false;
}

int stream_pointer::return_decimal_value(const char c)
{
    switch(c)
    {
        case 'I': case 'i':
            return 1;
        case 'V': case 'v':
            return 5;
        case 'X': case 'x':
            return 10;
        case 'L': case 'l':
            return 50;
        case 'C': case 'c':
            return 100;
        case 'D': case 'd':
            return 500;
        case 'M': case 'm':
            return 1000;
    }
    return -1;
}

bool stream_pointer::is_repeatable(char c)
{
    switch(c)
    {
        case 'i': case 'I': case 'x': case 'X':
        case 'c': case 'C': case 'm': case 'M':
        return true;
    }
    return false;
}