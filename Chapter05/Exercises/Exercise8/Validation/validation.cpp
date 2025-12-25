#include "headers.h"
#include "validation.h"

bool validation::are_zero(int& value_1, int& value_2)
{
    return value_1 == 0 || value_2 == 0;
}

void validation::sort(int& value_1, int& value_2)
{
    if(value_1 < value_2)
    {
        int smaller = value_1;
        value_1 = value_2;
        value_2 = smaller;
    }
}

bool validation::validate(int& value_1, int& value_2)
{
    if(are_zero(value_1, value_2))
    {
        std::cout << "Both numbers must be greater than zero" << std::endl;
        return false;
    }

    sort(value_1, value_2);
    return true;
}

bool validation::valid_operation(char& c)
{
    switch(c)
    {
        case 'p': case 'P': case 'c': case 'C': case 'q': case 'Q':
            return true;

        default:
            std::cout << "Please write 'p', 'c', or 'q'" << std::endl;
            return false;
    }
}