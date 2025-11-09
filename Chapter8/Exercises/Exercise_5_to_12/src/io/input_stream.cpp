#include "../../includes/io/input_stream.h"
#include <iostream>

input_stream::input_stream(): c('\0') {}
input_stream::~input_stream() {}

models::token input_stream::get_command()
{
    models::token t{};
    std::cin.get(c);
    if(isalpha(c))
    {
        c = std::tolower(c);
        t.m_cmd += c;
        while(std::cin.get(c) && c != ' ' && c != '\n')
        {
            c = std::tolower(c);
            t.m_cmd += c;
        }
        if(c != '\n') t.m_param = std::move(get_parameter());
        return t;
    }
    return t;
}

std::string input_stream::get_parameter()
{
    std::string param{""};
    while(c == ' ') std::cin.get(c);
    while(c != '\n')
    {
        param += c;
        std::cin.get(c);
    }
    return param;
}

std::string input_stream::await_string()
{
    std::string title{""};
    while(std::cin.get(c) && c != '\n')
    {
        title += c;
    }
    return title;
}

short input_stream::await_year()
{
    short year{0};
    while(std::cin.get(c) && isdigit(c))
    {
        year = year*10 + (c - '0');
    }
    clear_input();
    return year;
}

unsigned char input_stream::await_m_or_d()
{
    short date{0};
    while(std::cin.get(c) && isdigit(c))
    {
        date = date*10 + (c - '0');
    }
    clear_input();
    return static_cast<unsigned char>(date);
}

models::genre input_stream::await_genre()
{
    std::string gen{""};
    while(std::cin.get(c) && isalpha(c))
    {   
        c = std::tolower(c);
        gen += c;
    }
    if(gen == "fiction") return models::genre::fiction;
    if(gen == "biography") return models::genre::biography;
    if(gen == "nonfiction") return models::genre::nonfiction;
    if(gen == "periodical") return models::genre::periodical;
    if(gen == "children") return models::genre::children;
    return models::genre::unknown;
}

void input_stream::clear_input()
{
    while(c != '\n') std::cin.get(c);
}