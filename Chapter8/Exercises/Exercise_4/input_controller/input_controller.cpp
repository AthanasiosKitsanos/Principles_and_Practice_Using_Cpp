#include "input_controller.h"
#include <iostream>
#include <termination>
#include <clear_screen>

input_controller::input_controller() {}
input_controller::~input_controller() {}

name_pairs input_controller::get_name_pair(const std::string& name)
{
    double age{-1};
    char c;
    clear_screen();
    do
    {
        std::cout << "Enter " << name << "'s age: ";
        std::cin.get(c);
        if(isdigit(c))
        {
            age = get_number(c);
            continue;
        }
        if(isalpha(c))
        {
            std::cin.putback(c);
            if(get_input() != quit) std::cout << "Did you mean 'quit'?\n";
        }
    }while(age < 0);

    return name_pairs{name, age};
}

double input_controller::get_number(char& c)
{
    double number = c - '0';
    while(std::cin.get(c) && isdigit(c))
    {
        number = number*10 + (c - '0');
    }
    clean_input_stream(c);
    return number;
}

std::string input_controller::get_input()
{
    std::string input{""};
    for(char c; std::cin.get(c) && isalpha(c);)
    {
        input += c;
    }
    if(input == quit) throw TerminationException{"Termination Requested"};
    return input;
}

void input_controller::clean_input_stream(char& c)
{
    while(c != '\n') { std::cin.get(c); };
}

void input_controller::clean_input_spaces(char& c)
{
    while(c == ' ') { std::cin.get(c); };
    std::cin.putback(c);
}