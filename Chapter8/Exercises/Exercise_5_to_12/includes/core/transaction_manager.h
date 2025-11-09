#pragma once
#include <vector>
#include <unordered_map>
#include "../models/transaction.h"
#include "../utilities/commands.h"
#include "../io/input_stream.h"

namespace core
{
    class token;
    class book_manager;
    class patron_manager;

    class transaction_manager
    {
        std::vector<models::transaction> m_transactions;
        std::unordered_map<std::string, utilities::command>* m_cmd_map;
        book_manager* m_bm;
        patron_manager* m_pm;
        models::token* m_tk;
        input_stream m_is;
        bool running;

        void transaction_menu();
        utilities::command await_command();
        void execute_command(const utilities::command& cmd);
        void check_out_book();
        void check_in_book();
        void find_patron_with_fee() const;
        
        public:
            transaction_manager(std::unordered_map<std::string, utilities::command>* cmd_map, book_manager* bm, patron_manager* pm, models::token* tk);
            ~transaction_manager();

            const std::vector<models::transaction>& get_transactions_history() const;
            void run();
    };
}

std::ostream& operator<<(std::ostream& os, const std::vector<models::transaction>& transactions);