#include "book_manager.h"

namespace library
{
    book_manager::book_manager() {}
    book_manager::~book_manager() {}

    void book_manager::menu()
    {
        
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<library::book>& bl)
{
    for(int i = 0; i < bl.size(); i++)
    {
        os << bl[i] << '\n';
    }
    return os;
}