#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string& s, const std::string& w)
{
    // Create a funtions that checks if the character is a space or a character in w string
    auto is_delim = [&](char c) { return isspace(c) || w.find(c) != std::string::npos; };

    std::vector<std::string> vec;
    size_t end{0};
    // Reserve a size for the vector to avoid allocations
    {
        size_t size{0};
        size_t temp_index{0};
        while(temp_index < s.length() && is_delim(s[temp_index])) ++temp_index;

        // Keep where the first word starts in the string for later use
        end = temp_index;

        // Find how many word the string has and increase the size we want to reserve
        while(temp_index < s.length())
        {
            while(temp_index < s.length() && is_delim(s[temp_index])) ++temp_index;
            if(temp_index >= s.length()) break;
            while(temp_index < s.length() && !is_delim(s[temp_index])) ++temp_index;
            ++size;
        }
        vec.reserve(size);
    }

    // Use the same method, but we add the word in the vector
    size_t start{0};
    while(end < s.length())
    {
        while(end < s.length() && is_delim(s[end])) ++end;
        if(end >= s.length()) break;
        start = end;
        while(end < s.length() && !is_delim(s[end])) ++end;
        std::string_view word(s.data() + start, end - start);
        vec.emplace_back(std::move(word));
    }
    return vec;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<std::string> words_list = std::move(split("   Today I got paid-for this % month", "-%()"));
    for(const std::string& word: words_list)
    {
        std::cout << word << '\n';
    }
    std::cout << std::flush;
}