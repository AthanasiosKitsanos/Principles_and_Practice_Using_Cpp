#include "book.h"
#include <cstring>


namespace library
{
    book::book(const std::string& t, const std::string& a, const std::string i, const copyright_date& cd): m_title(t), m_author(a), m_isbn(i), m_date(cd)
    {
        if(!is_valid_isbn()) throw invalid_isbn{"Invalid ISBN"};
    }

    book::~book() {}

    const std::string& book::get_title() const { return m_title; }
    const std::string& book::get_author() const { return m_author; }
    const std::string& book::get_isbn() const { return m_isbn; }
    const copyright_date& book::get_c_date() const { return m_date; }
    const bool& book::is_checked_out() const { return m_checked_out; }
    void book::check_in() { m_checked_out = false; }
    void book::check_out() { m_checked_out = true; }

    bool book::is_valid_isbn()
    {
        int i{0};
        do
        {
            if(!isdigit(m_isbn[i])) return false;
            i++;
        }while( i < 3);
        if(!isdigit(m_isbn[3] || !isalpha(m_isbn[3]))) return false;
        return true;
    }

    book::invalid_isbn::invalid_isbn(const char* msg)
    {
        message = static_cast<char*>(malloc(std::strlen(msg) + 1));
        if(message) std::strcpy(message, msg);
    }

    book::invalid_isbn::~invalid_isbn()
    {
        free(message);
    }

    const char* book::invalid_isbn::what() const noexcept
    {
        return message;
    }
}

std::ostream& operator<<(std::ostream& os, const library::book& book)
{
    return os << "Title: " << book.get_title()
        << "\n\tAuthor: " << book.get_author()
        << "\n\tISBN: " << book.get_isbn()
        << "\n\tAuthor: " << book.get_author()
        << "\n\tRelease Date: " << book.get_c_date()
        << "\n\tChecked out: " << (book.is_checked_out() ? "Available" : "Unavailable");
}