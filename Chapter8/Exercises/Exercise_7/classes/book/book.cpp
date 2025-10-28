#include "book.h"
#include <cstring>

namespace library
{
    book::book():m_date(1, 1, 1), m_checked_out(false) {}
    book::book(const std::string& t, const std::string& a, const std::string& i, const copyright_date& cd, const genre& g): m_title(t), m_author(a), m_isbn(i), m_date(cd), gen(g), m_checked_out(false)
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
        if(m_isbn.size() != 4) return false;
        for(int i = 0; i < m_isbn.length() - 1; i++)
        {
            if(!isdigit(m_isbn[i])) return false;
        }
        if(!isdigit(m_isbn[m_isbn.length() - 1]) && !isalpha(m_isbn[m_isbn.length() - 1])) return false;
        return true;
    }

    const std::string book::get_genre() const
    {
        switch(gen)
        {
            case genre::biography:
                return "Biograpgy";
            case genre::children:
                return "Children";
            case genre::fiction:
                return "Fiction";
            case genre::nonfiction:
                return "Non-Fiction";
            case genre::periodical:
                return "Periodical";
        }
        return "No genre added";
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

    bool book::operator==(const book& other) { return m_isbn == other.m_isbn; }

    bool book::operator!=(const book& other) { return m_isbn != other.m_isbn; }
}

std::ostream& operator<<(std::ostream& os, const library::book& book)
{
    return os << "Title: " << book.get_title()
    << "\nAuthor: " << book.get_author()
    << "\nISBN: " << book.get_isbn()
    << "\nAuthor: " << book.get_author()
    << "\nRelease Date: " << book.get_c_date()
    << "\nGenre: " << book.get_genre()
    << "\nChecked out: " << (book.is_checked_out() ? "Unavailable\n" : "Available\n");
}