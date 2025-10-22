#include "main_controller.h"
#include <iostream>
#include <termination>
#include <clear_screen>

main_controller::main_controller():c('\0') {}
main_controller::~main_controller() {}

void main_controller::prompt()
{
    clear_screen();
    std::cout << "1. Add Name 2. Remove Name 3. See List 4. Help 5.Quit\n";
}

void main_controller::wait_input()
{
    std::cin.get(c);
    if(isalpha(c))
    {
        std::cin.putback(c);
        std::string input = input_c.get_input();
        for(char& c: input) c = std::tolower(c);
        if(input == add_name) c = '1';
        else if(input == r_name) c = '2';        
        else if(input == list) c = '3';
        else if(input == help) c = '4';
        else
        {
            clear_screen();
            std::cout << "Enter a valid choice or number\nIf you need help with commands, write 'help'\n";
            std::cin.get(c);
            input_c.clean_input_stream(c);
        }
        return;
    }
    if(!isdigit(c))
    {
        clear_screen();
        std::cout << "Enter a valid choice or number\nIf you need help with commands, write 'help'\n";
        std::cin.get(c);
        input_c.clean_input_stream(c);
    }
}

void main_controller::execute_command()
{
    switch(c)
    {
        case '1':
            add_new_name();
            clear_screen();
            std::cout << "New Name added successfully\n";
            std::cin.get();
            break;
        case '2':
            remove_name();
            clear_screen();
            std::cout << "Name removed successfully\n";
            std::cin.get();
            break;
        case '3':
            clear_screen();
            std::cout << vec;
            std::cin.get();
            clear_screen();
            break;
        case '4':
            clear_screen();
            get_help();
            std::cin.get();
            break;
        case '5':
            throw TerminationException{"Termination Requested"};
        default:
            break;
    }
}

void main_controller::add_new_name()
{
    std::string name = input_c.get_input();
    if(name == "")
    {
        clear_screen();
        throw std::invalid_argument{"No name was given"};
    }
    name_pairs np = input_c.get_name_pair(name);
    vec.push_back(np);
}

void main_controller::remove_name()
{
    std::string name = input_c.get_input();
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i].get_name() == name)
        {
            vec.erase(vec.begin() + i);
            return;
        }
    }
    throw std::invalid_argument{"Name was not found"};
}

void main_controller::get_help()
{
    std::cout << "Commands:\n";
    std::cout << "\tadd 'name': Adds a new name on the list\n";
    std::cout << "\tremove 'name': Removes a name from the list\n";
    std::cout << "\tlist: Prints all name on the list\n";
    std::cout << "\tquit: Terminates the program\n";
}

std::ostream& operator<<(std::ostream& os, const std::vector<name_pairs>& vec)
{
    if(vec.size() == 0) { return os << "List is empty"; }
    int i{0};
    for(; i + 3 < vec.size(); i += 4)
    {
        os << vec[i].get_name() << vec[i].get_age() << " years old\n";
        os << vec[i + 1].get_name() << ' ' << vec[i + 1].get_age() << " years old\n";
        os << vec[i + 2].get_name() << ' ' << vec[i + 2].get_age() << " years old\n";
        os << vec[i + 3].get_name() << ' ' << vec[i + 3].get_age() << " years old\n";
    }
    for(; i < vec.size(); i++)
    {
        os << vec[i].get_name() << ' ' << vec[i].get_age() << " years old\n";
    }
    return os;
}