#pragma once
#include <vector>
#include "../models/patrons.h"
#include "../../includes/io/input_stream.h"
#include "../../includes/utilities/commands.h"
#include <unordered_map>
#include <ostream>

namespace core
{
    class token;

    class patron_manager
    {
        std::vector<models::patron> m_patrons;
        std::unordered_map<std::string, utilities::command>* m_cmd_map;
        models::token* m_tk;
        input_stream m_is;
        bool running;

        bool id_exists(const short& id);
        void find_patron();
        void add_patron();
        void remove_patron();
        void sort_patrons();
        void patron_menu();
        utilities::command await_command();
        void execute_command(const utilities::command& cmd);

        public:
            patron_manager(models::token* tk, std::unordered_map<std::string, utilities::command>* cmd);
            ~patron_manager();

            bool patron_exists(const std::string& name) const;
            models::patron* get_patron_address(const std::string& name);
            void initialize();
            void run();
    };
}

std::ostream& operator<<(std::ostream& os, const std::vector<models::patron>& vec);