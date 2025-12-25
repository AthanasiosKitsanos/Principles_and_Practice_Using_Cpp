#include "v_handler.h"
#include <random>
#include <iostream>
#include <algorithm>

vector_handler::vector_handler(int s): size(s)
{
    vector.resize(size);

    std::cout << "Size: " << vector.size() << std::endl;

    insert_values();

    std::sort(vector.begin(), vector.end());
    
    implement_maxv();

    implement_minv();

    implement_median();

    implement_mean();
}

vector_handler::~vector_handler() {}

void vector_handler::insert_values()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(0, 10);

    int i = 0;
    for(; i + 3 < vector.size(); i += 4)
    {
        vector[i] = dist(gen);
        vector[i + 1] = dist(gen);
        vector[i + 2] = dist(gen);
        vector[i + 3] = dist(gen);
    }

    for(; i < vector.size(); i++)
    {
        vector[i] = dist(gen);
    }
}

void vector_handler::implement_maxv()
{
    int biggest = vector[0];
    int i = 0;
    int step = 5;

    for(i = 1; i + step - 1 < vector.size(); i += step)
    {
        if(vector[i] > biggest) biggest = vector[i];

        if(vector[i + 1] > biggest) biggest = vector[i + 1];

        if(vector[i + 2] > biggest) biggest = vector[i + 2];

        if(vector[i + 3] > biggest) biggest = vector[i + 3];

        if(vector[i + 4] > biggest) biggest = vector[i + 4];
    }

    for(; i < vector.size(); i++)
    {
        if(vector[i] > biggest) biggest = vector[i];
    }

    max_value = biggest;
}

void vector_handler::implement_minv()
{
    int minimum = vector[0];
    int i = 0;
    int step = 5;

    for(i = 1; i + step - 1 < vector.size(); i += step)
    {
        if(vector[i] < minimum) minimum = vector[i];

        if(vector[i + 1] < minimum) minimum = vector[i + 1];

        if(vector[i + 2] < minimum) minimum = vector[i + 2];

        if(vector[i + 3] < minimum) minimum = vector[i + 3];

        if(vector[i + 4] < minimum) minimum = vector[i + 4];
    }

    for(; i < vector.size(); i++)
    {
        if(vector[i] < minimum) minimum = vector[i];
    }

    min_value = minimum;
}

void vector_handler::implement_median()
{
    if(vector.size() % 2 == 1)
    {
        median = static_cast<float>(vector[vector.size() / 2]);
        return;
    }

    median = (vector[vector.size() / 2 - 1] + vector[vector.size() / 2]) / 2.0f;
}

void vector_handler::implement_mean()
{
    int i = 0;
    float sum = 0;

    for(; i + 4 < vector.size(); i += 5)
    {
        sum += vector[i] + vector[i + 1] + vector[i + 2] + vector[i + 3] + vector[i + 4];
    }

    for(; i < vector.size(); i++)
    {
        sum += vector[i];
    }

    mean = static_cast<float>(sum) / vector.size();
}

void vector_handler::print_vector()
{
    int i = 0;

    std::cout << "Vector: { ";

    for(; i + 4 < vector.size(); i += 5)
    {
        std::cout << vector[i] << ", " << vector[i + 1] << ", " << vector[i + 2] << ", " << vector[i + 3] << ", " << vector[i + 4];

        if(i + 4 < vector.size() - 1)
        {
            std::cout << ", ";
        }
    }

    for(; i < vector.size(); i++)
    {
        std::cout << vector[i];

        if(i < vector.size() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << " }" << std::endl;
}

int vector_handler::get_max()
{
    return max_value;
}

int vector_handler::get_min()
{
    return min_value;
}

float vector_handler::get_mean()
{
    return mean;
}

float vector_handler::get_median()
{
    return median;
}