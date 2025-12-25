#pragma once

#include <vector>

struct stream_pointer
{
    const char* start;

    stream_pointer();
    ~stream_pointer();

    bool is_valid_r_numeral(const char c) noexcept;
    int return_decimal_value(const char c);
    bool is_repeatable(char c);
};