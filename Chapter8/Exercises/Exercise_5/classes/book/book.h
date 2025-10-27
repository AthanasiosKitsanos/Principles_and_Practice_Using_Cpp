#pragma once
#include "copyright_date.h"
#include <string>
#include <exception>
#include <ostream>

namespace library
{
    class book
    {
        std::string m_title; // 0 -> 31
        std::string m_author; // 32 -> 63
        std::string m_isbn; // 64 -> 95 isbn is made of 4 characters, the 1st three should be digits and the last can be a digit or a letter
        copyright_date m_date; // 96 -> 99
        bool m_checked_out; // 100 
        bool is_valid_isbn();

        public:
            book();
            book(const std::string& t, const std::string& a, const std::string& i, const copyright_date& cd);
            ~book();

            const std::string& get_title() const;
            const std::string& get_isbn() const;
            const std::string& get_author() const;
            const copyright_date& get_c_date() const;
            const bool& is_checked_out() const;

            void check_in();
            void check_out();

            class invalid_isbn: public std::exception
            {
                char* message;

                public:
                    invalid_isbn(const char* msg);
                    ~invalid_isbn();

                    const char* what() const noexcept override;
            };
    };
}

std::ostream& operator<<(std::ostream& os, const library::book& book);