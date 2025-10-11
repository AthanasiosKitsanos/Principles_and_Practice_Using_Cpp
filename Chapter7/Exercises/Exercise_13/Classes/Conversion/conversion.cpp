#include "conversion.h"
#include <iostream>
#include <algorithm>
#include "vec_token.h"

vector_conversion::vector_conversion():sorted(false)
{
    string_vector =
    {
        "apple", "banana", "orange", "quit", "grape",
        "melon", "kiwi", "peach", "plum", "mango",
        "cherry", "pear", "lime", "quit", "apricot",
        "fig", "papaya", "date", "berry", "lemon"
    };
}

vector_conversion::~vector_conversion() {}

void vector_conversion::get_string_length()
{
    int i = 0;
    for(; i + 4 < string_vector.size(); i += 5)
    {
        std::cout << string_vector[i] << ": " << string_vector[i].length() << " letters\n";
        std::cout << string_vector[i + 1] << ": " << string_vector[i + 1].length() << " letters\n";
        std::cout << string_vector[i + 2] << ": " << string_vector[i + 2].length() << " letters\n";
        std::cout << string_vector[i + 3] << ": " << string_vector[i + 3].length() << " letters\n";
        std::cout << string_vector[i + 4] << ": " << string_vector[i + 4].length() << " letters\n";
    }

    for(; i < string_vector.size(); i++)
    {
        std::cout << string_vector[i] << ": " << string_vector[i].length() << " letters\n";
    }
}

void vector_conversion::print_min_and_max_length()
{
    if(!sorted)
    {
        std::sort(string_vector.begin(), string_vector.end());
        sorted = true;
    }
    vec_token greater_token = get_greatest_length();
    vec_token smallest_token = get_smallest_length();
    std::cout << "Biggest length: " << greater_token.get_length() << '\t' << "Word: " << greater_token.get_word() << '\n';
    std::cout << "Smallest length: " << smallest_token.get_length() << '\t' << "Word: " << smallest_token.get_word() << '\n';
}

vec_token vector_conversion::get_greatest_length()
{
    vec_token token{string_vector[0], static_cast<int>(string_vector[0].length())}; 
    for(int i = 1; i < string_vector.size(); i++)
    {
        if(token.get_length() < string_vector[i].length())
        {
            token.set_word(string_vector[i]);
            token.set_length(string_vector[i].length());
        }
    }
    return token;
}

vec_token vector_conversion::get_smallest_length()
{
    vec_token token{string_vector[0], static_cast<int>(string_vector[0].length())}; 
    for(int i = 1; i < string_vector.size(); i ++)
    {
        if(token.get_length() > string_vector[i].length())
        {
            token.set_word(string_vector[i]);
            token.set_length(string_vector[i].length());
        }
    }
    return token;
}

void vector_conversion::print_smallest_and_biggest_word()
{
    if(!sorted)
    {
        std::sort(string_vector.begin(), string_vector.end());
        sorted = true;
    }
    std::cout << "Lexicographical comparison:\n";
    std::cout << "Smallest word: " << string_vector[0] << '\n';
    std::cout << "Biggest word: " << string_vector[string_vector.size() - 1] << '\n';
}