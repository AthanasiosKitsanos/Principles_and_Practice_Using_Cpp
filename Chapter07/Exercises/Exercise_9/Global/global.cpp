#include "global.h"

void value_insertion(std::vector<float>& vec)
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<float> dist(0.1, 9.9);

    std::cout << "{ ";
    for(int i = 0; i < vec.size() - 1; i += 2)
    {
        vec[i] = dist(gen);
        vec[i + 1] = dist(gen);

        std::cout << vec[i] << ", " << vec[i + 1];

        if(i < vec.size() - 2)
        {
            std::cout << ", ";
        }
    }

    std::cout << " }" << std::endl;
}

float calculate_index_sum(const std::vector<float>& weight, const std::vector<float>& price)
{
    float sum = 0;

    std::cout << std::endl;
    for(int i = 0; i < weight.size() - 1; i += 2)
    {
        sum += weight[i]*price[i];

        sum += weight[i + 1]*price[i + 1];
    }

    return sum; 
}