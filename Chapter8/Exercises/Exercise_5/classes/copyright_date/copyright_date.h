#pragma once
#include <exception>
#include <ostream>

class copyright_date
{
    short year;
    unsigned char month;
    unsigned char day;
    bool is_valid_date();

    public:
        copyright_date(const short& y, const unsigned char& m, const unsigned char& d);
        ~copyright_date();

        short get_year() const;
        unsigned char get_month() const;
        unsigned char get_day() const;

        class invalid: public std::exception
        {
            char* message;

            public:
                invalid(const char* c);
                ~invalid();

                const char* what() const noexcept override;
        };
};

std::ostream& operator<<(std::ostream& os, const copyright_date& date);