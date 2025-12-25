#pragma once
#include "copyright_date.h"

namespace models
{
    class books;

    struct book_date
    {
        books* m_book_ptr;
        copyright_date m_date_rented;

        book_date(books* book, const copyright_date& date);
        ~book_date();
    };
}