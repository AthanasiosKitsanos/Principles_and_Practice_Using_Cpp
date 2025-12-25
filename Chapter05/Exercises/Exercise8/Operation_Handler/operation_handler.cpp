#include "headers.h"
#include "operation_handler.h"
#include "permutation.h"
#include "combination.h"

operation_handler::operation_handler(char& c, int& val1, int& val2):choice(c), value1(val1), value2(val2) {}
operation_handler::~operation_handler() {}

int operation_handler::execute_operation()
{
    switch(choice)
    {
        case 'p': case 'P':
        {
            return permutation::permute(value1, value2);
        }

        case 'c': case 'C':
        {
            return combination::combine(value1, value2);
        }
    }

    return 1;
}