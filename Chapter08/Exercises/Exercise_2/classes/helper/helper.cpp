#include "helper.h"
#include <iostream>
#include <termination>

int build_number()
{
    double age{0};
    int cache{0};
    char c;
    std::cin >> age;
    while(std::cin.get(c) && isdigit(c))
    {
        std::cin.putback(c);
        std::cin >> cache;
        age = age*10 + cache;
    }
    while(c != enter)
    {
        std::cin.get(c);
    }
    return age;
}

std::string get_text()
{
    char c;
    std::string input = "";
    while(std::cin.get(c) && isalpha(c))
    {
        input += c;
    }
    clear_input(c);
    if(input == quit) throw TerminationException{"Termination Requested"};
    return input;
}

void clear_input(char& c)
{
    while(c != enter) 
    {
        std::cin.get(c);
    }
}