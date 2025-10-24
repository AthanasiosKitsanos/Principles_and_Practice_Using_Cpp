#pragma once

#include "book.h"
#include "i_stream.h"
#include <vector>
#include <ostream>

namespace library
{
    class book_manager
    {
        std::vector<book> m_book_lib;
        i_stream m_is;

        public:
            book_manager();
            ~book_manager();

            void menu();
    };
}

std::ostream& operator<<(std::ostream& os, const std::vector<library::book>& bl);