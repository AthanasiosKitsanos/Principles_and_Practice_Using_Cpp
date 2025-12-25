#include "../../includes/models/transaction.h"
#include "../../includes/models/books.h"
#include "../../includes/models/patrons.h"
#include "../../includes/utilities/search.h"

namespace models
{
    transaction::transaction(patron* ptn, books* bk, const copyright_date& date): m_patron(ptn)
    {
        int pos{utilities::search::get_lower_bound(m_rented, bk->get_title())};
        m_rented.emplace(m_rented.begin() + pos, bk, date);
    }

    transaction::~transaction()
    {
        int i{0};
        for(; i + 3 < m_rented.size(); i += 4)
        {
            m_rented[i].m_book_ptr = nullptr;
            m_rented[i + 1].m_book_ptr = nullptr;
            m_rented[i + 2].m_book_ptr = nullptr;
            m_rented[i + 3].m_book_ptr = nullptr;
        }
        for(; i < m_rented.size(); ++i)
        {
            m_rented[i].m_book_ptr = nullptr;
        }
        m_patron = nullptr;
    }

    const int transaction::size() const { return m_rented.size(); }
    const std::vector<book_date>& transaction::print_books() const { return m_rented; }
    std::vector<book_date>& transaction::get_books() { return m_rented; }

    patron* const transaction::operator->() const { return m_patron; }
    const patron& transaction::operator*()const { return *m_patron; }
}

std::ostream& operator<<(std::ostream& os, const std::vector<models::book_date> b_date)
{
    for(const models::book_date& bd: b_date)
    {
        os << *bd.m_book_ptr;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const models::transaction& trans)
{
    os << "Name: " << trans->patron_name()
    << "\nCard Id: " <<trans->patron_card_id()
    << "\n\nBooks:";
    for(const models::book_date& b: trans.print_books())
    {
        os << "\nTitle: " << b.m_book_ptr->get_title() << " ISBN: " << b.m_book_ptr->get_isbn()
        <<"\nRented: " << b.m_date_rented << " Return at: " << b.m_date_rented.next_workday() << " Days since epoch: " << b.m_date_rented.days_since_epoch();
    }
    return os;
}