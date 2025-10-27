#pragma once

#include "book.h"
#include "i_stream.h"
#include <vector>
#include <ostream>
#include "commands.h"

namespace library
{
    class book_manager
    {
        std::vector<book> m_book_lib;
        i_stream m_is;
        commands::type m_cmd;
        char c;

        public:
            book_manager();
            ~book_manager();

            void menu();
            void wait_command();
            void execute();
            void print_sizes();
            void add_new_book();
            void remove_book();
            int vec_lower_bound(const std::string& title);
            void vec_sort(std::vector<library::book>& vec);
            int vec_find_title(const std::string& title);
            void check_out_book();
            void check_in_book();
    };
}

std::ostream& operator<<(std::ostream& os, const std::vector<library::book>& bl);