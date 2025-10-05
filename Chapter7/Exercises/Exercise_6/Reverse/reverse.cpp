#include "reverse.h"

std::vector<std::string> reverse_to_new(std::vector<std::string> vec)
{
    std::string cached = "";

    for(int i = 0; i < vec.size(); i++)
    {
        int j = vec.size() - 1 - i;
        
        if(i >= j) return vec;

        cached = vec[i];
        vec[i] = vec[j];
        vec[j] = cached;
    }

    return std::vector<std::string>();
}

void reverse_original(std::vector<std::string>& vec)
{
    std::string cached = "";

    for(int i = 0; i < vec.size(); i++)
    {
        int j = vec.size() - 1 - i;

        if(i >= j) return;

        cached = vec[i];
        vec[i] = vec[j];
        vec[j] = cached;
    }
}