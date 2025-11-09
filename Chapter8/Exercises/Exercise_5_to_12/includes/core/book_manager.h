#pragma once
#include "../models/books.h"
#include "../io/input_stream.h"
#include "../../includes/utilities/commands.h"
#include <vector>
#include <ostream>
#include <unordered_map>

namespace core
{
    class token;

    class book_manager
    {
        std::vector<models::books> m_lib;
        models::token* m_tk;
        std::unordered_map<std::string, utilities::command>* m_cmd_map;
        input_stream m_is;
        bool running;

        void sort_lib();
        void library_menu();
        utilities::command await_command();
        void execute_command(const utilities::command& cmd);
        void add_book();
        void remove_book();
        bool isbn_exists(const std::string& isbn);
        void find_book();

        public:
            book_manager(models::token* tk, std::unordered_map<std::string, utilities::command>* cmd_map);
            ~book_manager();
            
            bool book_exists(const std::string& title) const;
            models::books* get_book_address(const std::string& title);
            void initialize();
            void run();
    };
}

std::ostream& operator<<(std::ostream& os, const std::vector<models::books>& vec);