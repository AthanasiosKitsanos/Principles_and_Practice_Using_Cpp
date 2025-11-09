#pragma once
#include <string>
#include "copyright_date.h"
#include <ostream>

namespace models
{
    enum class genre: short { fiction, nonfiction, periodical, biography, children, unknown };

    class books
    {
        std::string m_title;
        std::string m_author;
        std::string m_isbn;
        copyright_date m_date;
        genre m_gen;
        bool m_available;
        bool is_valid_isbn();

        public:
            books(const std::string& title, const std::string author, const std::string& isbn, const copyright_date& date, const genre& gen);
            ~books();

            const std::string& get_title() const;
            const std::string& get_author() const;
            const std::string& get_isbn() const;
            const copyright_date& get_date() const;
            const std::string get_genre() const;
            const bool& availability() const;

            void check_in();
            void check_out();

            bool operator==(const books& other);
            bool operator!=(const books& other);

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

std::ostream& operator<<(std::ostream& os, const models::books& book);