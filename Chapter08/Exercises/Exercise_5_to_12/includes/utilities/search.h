#pragma once
#include <vector>
#include <string>
#include "../models/books.h"
#include "../models/patrons.h"
#include "../models/transaction.h"
#include "../models/book_date.h"

namespace utilities
{
    class search
    {
        public:
            static int get_position(const std::vector<models::books>& vec, const std::string& title);
            static int get_position(const std::vector<models::patron>& vec, const std::string& name);
            static int get_position(const std::vector<models::transaction>& vec, const std::string& name);
            static int get_position(const std::vector<models::book_date>& vec, const std::string& name);
            static int get_lower_bound(const std::vector<models::books>& vec, const std::string& title);
            static int get_lower_bound(const std::vector<models::patron>& vec, const std::string& name);
            static int get_lower_bound(const std::vector<models::transaction>& vec, const std::string& name);
            static int get_lower_bound(const std::vector<models::book_date>& vec, const std::string& name);
    };
}