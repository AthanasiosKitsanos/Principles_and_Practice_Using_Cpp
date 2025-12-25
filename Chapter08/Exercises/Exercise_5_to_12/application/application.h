#pragma once
#include "../includes/io/input_stream.h"
#include "../includes/utilities/commands.h"
#include "../includes/core/book_manager.h"
#include "../includes/core/patron_manager.h"
#include "../includes/core/transaction_manager.h"
#include <unordered_map>

namespace console
{
    class application
    {
        std::unordered_map<std::string, utilities::command> m_cmd_map;
        core::book_manager m_bm;
        core::patron_manager m_pm;
        core::transaction_manager m_tm;
        models::token m_tk;
        input_stream m_is;
        bool running;
        void main_menu();
        utilities::command await_command();
        void execute_command(const utilities::command& cmd);
        
        public:
            application();
            ~application();

            void io_synchronization(const bool& is_sync);
            void use_library();
            void use_patron();
            void run();
    };
}