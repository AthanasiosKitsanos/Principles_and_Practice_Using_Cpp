    #pragma once
#include <ostream>
#include <exception>

namespace models
{
    enum class day_of_week: short { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

    class copyright_date
    {
        short m_year;
        day_of_week m_day_of_week;
        unsigned char m_month;
        unsigned char m_day;
        bool is_valid_date();
        bool is_leap_year() const;
        unsigned char days_in_month() const;
        short calculate_day_of_the_week();
        short days_to_add() const;

        public:
            copyright_date(const short& yy, const unsigned char& mm, const unsigned char& dd);
            ~copyright_date();

            const short& get_year() const;
            short get_month() const;
            short get_day() const;
            const std::string get_day_of_week() const;
            const copyright_date next_workday() const;
            unsigned long int days_since_epoch() const;

            class invalid_date: public std::exception
            {
            char* message;

                public:
                    invalid_date(const char* c);
                    ~invalid_date();

                    const char* what() const noexcept override;
            };

            bool operator==(const copyright_date& date) const;
            bool operator!=(const copyright_date& date) const;
    };
}

std::ostream& operator<<(std::ostream& os, const models::copyright_date& date);