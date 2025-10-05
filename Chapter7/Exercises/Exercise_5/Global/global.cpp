#include "global.h"
#include "g_headers.h"
#include "reverse.h"

void print_vector_elements(const std::vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];

        if(i == vec.size() - 1)
        {
            std::cout << std::endl;
            return;
        }

        std::cout << ", ";
    }
}

void run()
{
    std::vector<int> original_vector = { 1, 3, 5, 7, 9 };

    std::vector<int> reversed_vector = reverse_to_new(original_vector);

    std::cout << "Original: ";
    print_vector_elements(original_vector);

    std::cout << "New Reversed: ";
    print_vector_elements(reversed_vector);

    reverse_original(original_vector);

    std::cout << "Original, but reversed: ";
    print_vector_elements(original_vector);

    termination_prompt();
}