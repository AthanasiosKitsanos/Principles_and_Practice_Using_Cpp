#pragma once
#include <string_view>
#include <string>
#include <vector>

constexpr std::string_view stop = "stop";
constexpr char enter = '\n';
constexpr std::string_view quit = "quit"; 

int build_number();
std::string get_text();
void clear_input(char& c);
inline int find_name(const std::string& name, std::vector<std::string>& vec)
{
    int left{0};
    int right = vec.size() -1;
    int mid{0};
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(vec[mid] == name)
        {
            return mid;
        }
        else if(vec[mid] < name)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return -1;
}