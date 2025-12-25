#include "../../includes/utilities/search.h"

namespace utilities
{
    int search::get_position(const std::vector<models::books>& vec, const std::string& title)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(vec[mid].get_title() == title) return mid;
            else if(vec[mid].get_title() < title) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
    
    int search::get_position(const std::vector<models::patron>& vec, const std::string& name)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(vec[mid].patron_name() == name) return mid;
            else if(vec[mid].patron_name() < name) left = mid + 1;
            else right = mid;
        }
        return -1;
    }

    int search::get_position(const std::vector<models::transaction>& vec, const std::string& name)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(vec[mid]->patron_name() == name) return mid;
            else if(vec[mid]->patron_name() < name) left = mid + 1;
            else right = mid;
        }
        return -1;
    }

    int search::get_position(const std::vector<models::book_date>& vec, const std::string& name)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(vec[mid].m_book_ptr->get_title() == name) return mid;
            else if(vec[mid].m_book_ptr->get_title() < name) left = mid + 1;
            else right = mid;
        }
        return -1;
    }

    int search::get_lower_bound(const std::vector<models::books>& vec, const std::string& title)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(vec[mid].get_title() < title) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int search::get_lower_bound(const std::vector<models::patron>& vec, const std::string& name)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(vec[mid].patron_name() < name) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int search::get_lower_bound(const std::vector<models::transaction>& vec, const std::string& name)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(vec[mid]->patron_name() < name) mid = left + 1;
            else right = mid;
        }
        return left;
    }

    int search::get_lower_bound(const std::vector<models::book_date>& vec, const std::string& name)
    {
        int left{0};
        int right = static_cast<int>(vec.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(vec[mid].m_book_ptr->get_title() < name) mid = left + 1;
            else right = mid;
        }
        return left;
    }
}