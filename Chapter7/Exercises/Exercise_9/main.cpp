#include "global.h"

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    std::vector<float> weight(10);
    std::vector<float> price(10);

    std::cout << "Weight: ";
    value_insertion(weight);

    std::cout << "Price: ";
    value_insertion(price);

    float total = calculate_index_sum(weight, price);

    std::cout << "Total: " << total << std::endl;

    termination_prompt();

    return 0;
}