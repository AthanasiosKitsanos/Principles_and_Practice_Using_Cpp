#pragma once

#include <ostream>
#include <exception>
#include "month.h"
#include "year.h"

class date
{
    int d{1};
    month m{month::jan};
    year y{2000};
    bool is_valid();

    public:
        class invalid: public std::exception
        {
            std::string message;

            public:
                invalid(const std::string& msg):message(msg) {};

                const char* what() const noexcept override { return message.c_str(); }
        };
        date();
        date(const year& yy, const month& mm, const int& dd);
        ~date();

        month get_month() const { return m; }
        void add_day(const int& d);
        year get_year() const { return y; }
        int day() const { return d; }
};

std::ostream& operator<<(std::ostream& os, const date& d);