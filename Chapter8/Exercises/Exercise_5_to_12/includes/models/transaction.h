#pragma once
#include <vector>
#include <ostream>
#include "copyright_date.h"
#include "book_date.h"

namespace models
{
    class books;
    class patron;

    class transaction
    {
        std::vector<book_date> m_rented;
        patron* m_patron;
        
        public:
            transaction(patron* patron, books* book, const copyright_date& date);
            ~transaction();

            const int size() const;
            const std::vector<book_date>& print_books() const;
            std::vector<book_date>& get_books();

            patron* const operator->() const;
            const patron& operator*() const;
    };
}

std::ostream& operator<<(std::ostream& os, const std::vector<models::book_date> b_date);
std::ostream& operator<<(std::ostream& os, const models::transaction& trans);