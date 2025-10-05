#include "reverse.h"

std::vector<int> reverse_to_new(std::vector<int> vec)
{
    int cached = 0;

    for(int i = 0; i < vec.size(); i++)
    {
        int j = vec.size() - 1 - i;
        
        if(i >= j) return vec;

        cached = vec[i];
        vec[i] = vec[j];
        vec[j] = cached;
    }

    return std::vector<int>();
}

void reverse_original(std::vector<int>& vec)
{
    int cached = 0;

    for(int i = 0; i < vec.size(); i++)
    {
        int j = vec.size() - 1 - i;

        if(i >= j) return;

        cached = vec[i];
        vec[i] = vec[j];
        vec[j] = cached;
    }
}