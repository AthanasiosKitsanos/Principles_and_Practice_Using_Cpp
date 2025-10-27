#include "i_stream.h"
#include <iostream>
#include <termination>

i_stream::i_stream() {}
i_stream::~i_stream() {}

std::string i_stream::get_input(char& c)
{
    std::string command{""};
    while(std::cin.get(c) && (isalpha(c) || isdigit(c) || c == ' '))
    {
        command += c;
    }
    if(command == "close") throw TerminationException{"Termination Requested"};
    clear_buffer(c);
    return command;
}

short i_stream::get_short(char& c)
{
    short year{0};
    while(std::cin.get(c) && isdigit(c))
    {
        year = year*10 + (c - '0');
    }
    clear_buffer(c);
    return year;
}

unsigned char i_stream::get_usinged_char(char& c)
{
    short date{0};
    while(std::cin.get(c) && isdigit(c))
    {
        date = date*10 + (c - '0');
    }
    clear_buffer(c);
    return static_cast<unsigned char>(date);
}

void i_stream::clear_buffer(char& c)
{
    while(c != '\n') std::cin.get(c);
}