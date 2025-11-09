#include "../../includes/models/patrons.h"
#include <cstring>
#include <cstdlib>

namespace models
{
    patron::patron(const std::string& name, const short& card_id, const copyright_date& date): m_name(name), m_card_id(card_id), m_fees(0), m_joined(date)
    {
        if(!is_valid_id()) throw invalid_id{"Invalid Id"};
    }
    patron::~patron() {}

    const std::string& patron::patron_name() const { return m_name; }
    const short& patron::patron_card_id() const { return m_card_id; }
    const copyright_date& patron::date_joined() const { return m_joined; }
    const short& patron::patron_fees() const { return m_fees; }
    
    bool patron::is_valid_id()
    {
        return m_card_id > 999 && m_card_id < 10000;
    }

    patron::invalid_id::invalid_id(const char* msg)
    {
        message = static_cast<char*>(malloc(std::strlen(msg) + 1));
        if(message) std::strcpy(message, msg);
    }

    patron::invalid_id::~invalid_id() { free(message); }

    const char* patron::invalid_id::what() const noexcept { return message; }

    void patron::set_fee(const short& fee)
    {
        m_fees += fee;
    }

    bool patron::operator==(const patron& other)
    {
        return m_card_id == other.m_card_id;
    }

    bool patron::operator!=(const patron& other)
    {
        return m_card_id != other.m_card_id;
    }
}

std::ostream& operator<<(std::ostream& os, const models::patron& pt)
{
    return os << "Name: " << pt.patron_name()
    << "\nCard Id: " << pt.patron_card_id()
    << "\nJoined: " << pt.date_joined() << " Days since epoch: " << pt.date_joined().days_since_epoch()
    << "\nOwes: " << pt.patron_fees() << '\n';
}