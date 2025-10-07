#include "global.h"
#include <random>
#include <iostream>

void insert_values(std::vector<int>& vec)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(0, INT_MAX);

    int i = 0;
    for(; i < vec.size() - 3; i += 4)
    {
        vec[i] = dist(gen);
        vec[i + 1] = dist(gen);
        vec[i + 2] = dist(gen);
        vec[i + 3] = dist(gen);
    }

    for(; i < vec.size(); i++)
    {
        vec[i] = dist(gen);
    }
}

int maxv(const std::vector<int>& vec)
{
    int biggest = vec[0];
    int i = 0;
    int step = 5;

    for(i = 1; i + step - 1 < vec.size(); i += step)
    {
        if(vec[i] > biggest) biggest = vec[i];

        if(vec[i + 1] > biggest) biggest = vec[i + 1];

        if(vec[i + 2] > biggest) biggest = vec[i + 2];

        if(vec[i + 3] > biggest) biggest = vec[i + 3];

        if(vec[i + 4] > biggest) biggest = vec[i + 4];
    }

    for(; i < vec.size(); i++)
    {
        if(vec[i] > biggest) biggest = vec[i];
    }

    return biggest;
}