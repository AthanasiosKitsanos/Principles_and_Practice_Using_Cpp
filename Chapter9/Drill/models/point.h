#pragma once
#include "pch.h"

class point
{
    public:
        double x, y;
        bool is_valid;
        point();
        ~point();

        void reset();
        void invalid();

        bool operator==(const point& other) const;
        bool operator!=(const point& other) const;
};

std::ostream& operator<<(std::ostream& os, const point& p);
std::ostream& operator<<(std::ostream& os, const std::vector<point>& vec);
std::istream& operator>>(std::istream& is, point& p);