#pragma once
#include "input_stream.h"
#include "token.h"

class flow_handler
{
    private:
        token t;
        int value1;
        int value2;
        int result;
        bool exit;

        void get_numbers();
        void get_operation();
        void execute_operation();
        
    public:
        flow_handler();
        ~flow_handler();

        static flow_handler* initialize_handler();
        static void free_flow_handler(flow_handler*& ptr);
        void run();
};