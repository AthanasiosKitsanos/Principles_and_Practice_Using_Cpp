#pragma once
#include "pch.h"

constexpr int imlausible_min = -200;
constexpr int imlausible_max = 200;
constexpr int not_a_reading = -777;

struct reading
{
    double temperature;
    int day;
    int hour;

    reading(const double& t);
    reading(const double& t, const int d, const int h);
    ~reading();

    bool is_implausible_temp();
    bool is_valid_day();
    bool is_valid_hour();
};

std::istream& operator>>(std::istream& is, reading& r);
std::ostream& operator<<(std::ostream& os, const reading& r);