#pragma once
#include <vector>
#include "name_pairs.h"
#include "input_controller.h"
#include <ostream>

class main_controller
{
    std::vector<name_pairs> vec;
    input_controller input_c;
    char c;

    void add_new_name();
    void remove_name();
    void get_help();

    public:
        main_controller();
        ~main_controller();

        void prompt();
        void wait_input();
        void execute_command();
};

std::ostream& operator<<(std::ostream& os, const std::vector<name_pairs>& vec);