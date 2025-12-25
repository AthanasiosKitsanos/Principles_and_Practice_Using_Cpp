#include "../../includes/models/book_date.h"
#include "../../includes/models/books.h"

namespace models
{
    book_date::book_date(books* book, const copyright_date& date): m_book_ptr(book), m_date_rented(date) {}
    book_date::~book_date()
    {
        m_book_ptr = nullptr;
        m_date_rented.~copyright_date();
    }
}