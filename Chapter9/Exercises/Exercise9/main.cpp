#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string& s)
{
    std::vector<std::string> vec;
    size_t start{0};
    for(size_t i{0}; i < s.length(); ++i)
    {
        if(isspace(s[i]))
        {
            std::string_view word(s.data() + start, i - start);
            vec.emplace_back(std::move(word));
            start = i + 1;
        }
    }
    if(start < s.length())
    {
        std::string_view word(s.data() + start);
        vec.emplace_back(std::move(word));
    }
    return vec;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<std::string> vec = std::move(split("Today is the "));
    for(const std::string& s: vec)
    {
        std::cout << s << '\n';
    }
    std::cout << std::flush;
}