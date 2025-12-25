#include "../../includes/models/books.h"
#include <cstring>
#include <cstdlib>

namespace models
{
    books::books(const std::string& title, const std::string author, const std::string& isbn, const copyright_date& date, const genre& gen)
    : m_title(title), m_author(author), m_isbn(isbn), m_date(date), m_gen(gen), m_available(true)
    {
        if(!is_valid_isbn()) throw invalid_isbn{"Invalid ISBN"};
    }

    books::~books() {}

    const std::string& books::get_title() const { return m_title; }
    const std::string& books::get_author() const { return m_author; }
    const std::string& books::get_isbn() const { return m_isbn; }
    const copyright_date& books::get_date() const { return m_date; }
    const bool& books::availability() const { return m_available; }
    const std::string books::get_genre() const
    { 
        switch(m_gen)
        {
            case genre::biography:
                return "Biography";
            case genre::children:
                return "Children";
            case genre::fiction:
                return "Fiction";
            case genre::nonfiction:
                return "Non-Fiction";
            case genre::periodical:
                return "Periodical";
            default:
                return "Unknown";
        }
    }

    void books::check_in() { m_available = true; }
    void books::check_out() { m_available = false; }

    bool books::operator==(const books& other) { return m_isbn == other.m_isbn; }
    bool books::operator!=(const books& other) { return m_isbn != other.m_isbn; }

    bool books::is_valid_isbn()
    {
        if(m_isbn.size() != 4) return false;
        for(int i = 0; i < m_isbn.length() - 1; i++)
        {
            if(!isdigit(m_isbn[i])) return false;
        }
        if(!isdigit(m_isbn[m_isbn.length() - 1]) && !isalpha(m_isbn[m_isbn.length() - 1])) return false;
        return true;
    }

    books::invalid_isbn::invalid_isbn(const char* msg)
    {
        message = static_cast<char*>(malloc(std::strlen(msg) + 1));
        if(message) std::strcpy(message, msg);
    }

    books::invalid_isbn::~invalid_isbn() { free(message);}

    const char* books::invalid_isbn::what() const noexcept { return message; }
}

std::ostream& operator<<(std::ostream& os, const models::books& book)
{
    return os << "Title: " << book.get_title()
    << "\nAuthor: " << book.get_author()
    << "\nISBN: " << book.get_isbn()
    << "\nDate: " << book.get_date() << " Days Since Epoch: " << book.get_date().days_since_epoch()
    << "\nGenre: " << book.get_genre()
    << "\nAvailable: " << (book.availability() ? "Yes\n" : "No\n");
}