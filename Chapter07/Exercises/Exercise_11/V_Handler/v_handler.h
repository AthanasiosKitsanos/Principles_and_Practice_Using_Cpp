#pragma once
#include <vector>

class vector_handler
{
    int size;
    int max_value;
    int min_value;
    float median;
    float mean;

    public:
        vector_handler(int size);
        ~vector_handler();

        std::vector<int> vector;
        void insert_values();
        void implement_maxv();
        void implement_minv();
        void implement_mean();
        void implement_median();
        void print_vector();

        int get_max();
        int get_min();
        float get_median();
        float get_mean();
};