#pragma once
#include <string_view>
#include "name_pairs.h"

constexpr std::string_view quit = "quit";
constexpr std::string_view add_name = "add";
constexpr std::string_view r_name = "remove";
constexpr std::string_view list = "list";
constexpr std::string_view help = "help";

class input_controller
{
    double get_number(char& c);

    public:
        input_controller();
        ~input_controller();

        name_pairs get_name_pair(const std::string& name);
        std::string get_input();
        void clean_input_stream(char& c);
        void clean_input_spaces(char& c);
};