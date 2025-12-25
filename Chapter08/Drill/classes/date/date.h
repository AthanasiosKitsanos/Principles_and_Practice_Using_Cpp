#pragma once

#include <ostream>
#include <exception>
#include "month.h"
#include "year.h"
#include "day.h"

class date
{
    day d{1};
    month m{month::jan};
    year y{2000};
    bool is_valid_month();
    bool is_valid_day();

    public:
        class invalid: public std::exception
        {
            std::string message;

            public:
                invalid(const std::string& msg):message(msg) {};

                const char* what() const noexcept override { return message.c_str(); }
        };
        date();
        date(const year& yy);
        date(const day& dd);
        date(const month& mm);
        date(const year& yy, const month& mm);
        date(const year& yy, const day& dd);
        date(const month& mm, const day& dd);
        date(const year& yy, const month& mm, const day& dd);
        ~date();

        month get_month() const { return m; }
        void add_day(const int& d);
        year get_year() const { return y; }
        day get_day() const { return d; }
};

std::ostream& operator<<(std::ostream& os, const date& d);