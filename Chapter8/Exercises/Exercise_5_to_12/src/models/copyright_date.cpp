#include "../../includes/models/copyright_date.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace models
{   
    copyright_date::copyright_date(const short& yy, const unsigned char& mm, const unsigned char& dd): m_year(yy), m_month(mm), m_day(dd)
    {
        if(!is_valid_date()) throw invalid_date{"Invalid Date"};
        m_day_of_week = day_of_week{calculate_day_of_the_week()};
    }

    copyright_date::~copyright_date() {}

    const short& copyright_date::get_year() const { return m_year; }
    short copyright_date::get_month() const { return m_month; }
    short copyright_date::get_day() const { return m_day; }
    const std::string copyright_date::get_day_of_week() const
    {
        switch(m_day_of_week)
        {
            case day_of_week::sunday:
                return "Sunday";
            case day_of_week::monday:
                return "Monday";
            case day_of_week::tuesday:
                return "Tuesday";
            case day_of_week::wednesday:
                return "Wednesday";
            case day_of_week::thursday:
                return "Thursday";
            case day_of_week::friday:
                return "Friday";
            case day_of_week::saturday:
                return "Saturday";
        }
        return "Unknown Day\n";
    }

    bool copyright_date::is_valid_date()
    {
        return (m_year > 1969 && m_year < 9999) && (m_month < 13 && m_month > 0) && (m_day > 0 && m_day <= days_in_month());
    }

    //added leap year
    bool copyright_date::is_leap_year() const
    {
        return ( m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0;
    }

    //what the day should be based on the month
    unsigned char copyright_date::days_in_month() const
    {
        switch(m_month)
        {
            case 2:
                return is_leap_year() ? 29 : 28;
            case 4: case 6:
            case 9: case 11: 
                return 30;
            default:
                return 31;
        }
    }

    short copyright_date::calculate_day_of_the_week() // This sets the day of the week
    {
        int q = m_day;
        int m = m_month;
        int y = m_year;
        if(m < 3)
        {
            m += 12;
            y -= 1;
        }
        int K = y % 100;
        int J = y / 100;
        return (((q + (13 * (m + 1))/ 5 + K + K/4 + J/4 + 5*J) % 7) + 6) % 7;
    }


    short copyright_date::days_to_add() const
    {
        switch(m_day_of_week)
        {
            case day_of_week::saturday:
                return 2;
            case day_of_week::friday:
                return 3;
            default:
                return 1;
        }
    }

    const copyright_date copyright_date::next_workday() const
    {
        short year{m_year};
        unsigned char month{m_month};
        unsigned char day{m_day};
        if(day + days_to_add() > days_in_month())
        {
            day = static_cast<unsigned char>((m_day + days_to_add()) - days_in_month());
            month++;
            if(month > 12)
            {
                month = 1;
                year++;
            }
            return copyright_date{year, month, day};
        }
        day = static_cast<unsigned char>(day + days_to_add());
        return copyright_date{year, month, day};
    }

    unsigned long int copyright_date::days_since_epoch() const
    {   
        short year = m_year;
        unsigned char month = m_month;
        unsigned char day = m_day;
        if(month <= 2)
        {
            year -= 1;
            month += 12;
        }
        return (365L*year + year/4 - year/100 + year/400 + (153*(month - 3) + 2)/5 + day - 1) - 719568;
    }

    copyright_date::invalid_date::invalid_date(const char* msg)
    {
        message = static_cast<char*>(malloc(std::strlen(msg) + 1));
        if(message) strcpy(message, msg);
    }

    copyright_date::invalid_date::~invalid_date() { free(message); }

    const char* copyright_date::invalid_date::what() const noexcept { return message; }

    bool copyright_date::operator!=(const copyright_date& other) const
    {
        return m_year != other.m_year || m_month != other.m_month || m_day == other.m_day;
    }

    bool copyright_date::operator==(const copyright_date& other) const
    {
        return m_year == other.m_year && m_month == other.m_month && m_day == other.m_day;
    }
}

std::ostream& operator<<(std::ostream& os, const models::copyright_date& date)
{   
    return os << date.get_day_of_week() << ' ' << date.get_day() << '/' << date.get_month() << '/' << date.get_year();
}