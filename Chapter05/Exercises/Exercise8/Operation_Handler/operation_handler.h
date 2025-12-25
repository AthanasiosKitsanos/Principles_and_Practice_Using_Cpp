#pragma once

class operation_handler
{
    private:
        int value1;
        int value2;
        char choice;

    public:
        operation_handler(char& c, int& val1, int& val2);
        ~operation_handler();

        int execute_operation();
};