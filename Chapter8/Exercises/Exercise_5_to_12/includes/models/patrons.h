#pragma once
#include <string>
#include <ostream>
#include "copyright_date.h"

namespace models
{
    class patron
    {
        std::string m_name;
        short m_card_id;
        short m_fees;
        copyright_date m_joined;
        bool is_valid_id();

        public:
            patron(const std::string& name, const short& card_id, const copyright_date& date);
            ~patron();

            const std::string& patron_name() const;
            const short& patron_card_id() const;
            const copyright_date& date_joined() const;
            const short& patron_fees() const;

            class invalid_id: public std::exception
            {
                char* message;

                public:
                    invalid_id(const char* c);
                    ~invalid_id();
                    const char* what() const noexcept override;
            };
        
            
        bool operator==(const patron& other);
        bool operator!=(const patron& other);
        void set_fee(const short& fee);
    }; 
}

std::ostream& operator<<(std::ostream& os, const models::patron& pt);