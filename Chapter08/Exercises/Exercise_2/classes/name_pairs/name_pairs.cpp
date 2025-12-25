#include "name_pairs.h"
#include <termination>
#include <algorithm>
#include <clear_screen>

void name_pairs::read_names(const bool& loop)
{
    char c;
    std::string n{""};
    do
    {
        std::cout << "Name: ";
        n = get_text();
        if(n.empty())
        {
            clear_screen();
            std::cout << "Name is empty\n";
            continue;
        }
        if(n == stop) return;
        if(n == quit) throw TerminationException{"Termination requested"}; // the user wants to terminate the program
        name.push_back(n);
        n = ""; // resets the n string to an empty string
        clear_screen();
        std::cout << "Name registered succesfully\n";
    }while(loop);
}

void name_pairs::read_ages(const bool& loop)
{
    clear_screen();
    char c;
    int i = loop ? 0: name.size() - 1;
    do
    {
        std::cout << "Enter " << name[i] << "'s age->";
        std::cin.get(c);
        if(isdigit(c))
        { 
            std::cin.putback(c);
            age.push_back(build_number());
            clear_screen();
            std::cout << "Age entered succesfully\n";
            i++;
            continue;
        }
        if(isalpha(c)) 
        {
            std::cin.putback(c);
            if(get_text() != quit) std::cout << "Did you mean 'quit'?\n";
        }
    }while(i < name.size());
}

void name_pairs::print()
{
    clear_screen();
    for(int i = 0; i < name.size(); i++)
    {
        std::cout << name[i] << ": " << age[i] << " years old" << std::endl;
    }
}

void name_pairs::sort_vectors()
{    
    std::string greater_name{""};
    int greater_age{0};
    for(int i = 0; i < name.size() - 1; i++)
    {
        for(int j = i + 1; j < name.size(); j++)
        {
            if(name[i] > name[j])
            {
                greater_name = name[i];
                name[i] = name[j];
                name[j] = greater_name;

                greater_age = age[i];
                age[i] = age[j];
                age[j] = greater_age;
            }
        }        
    }
}

name_pairs name_pairs::initialize()
{
    std::cout << "Starting initialization\n";
    name_pairs np;
    std::cout << "Enter a name: (enter stop to continue or quit to terminate):\n";
    np.read_names(true);
    std::cout << "Enter the age for each name you entered: (enter quit to terminate):\n";
    np.read_ages(true);
    np.sort_vectors();
    return np;
}

void name_pairs::add_name()
{
    std::cout << "Enter a new name:\n" ;
    read_names(false);
    read_ages(false);
    sort_new_addition();
}

void name_pairs::remove_name()
{
    std::cout << "Enter a name to remove: (enter stop to continue or quit to terminate):\n";
    std::string r_name = get_text();
    int index{0};
    if(r_name == stop)
    {
        std::cout << "Exiting name removal\n";
        return;
    }
    do
    {
        index = find_name(r_name, name);
        if(index != -1)
        {
            name.erase(name.begin() + index);
            age.erase(age.begin() + index);
            std::cout << "Name " << r_name << " successfully removed\n";
            return;
        }
        std::cout << "Name not found. Please try again\n";
    }while(true);
}

void name_pairs::sort_new_addition()
{
    double new_age = age.back();
    std::string new_name = name.back();
    int index = name.size() - 2;
    while(index >= 0 && name[index] > new_name)
    {
        name[index + 1] = name[index];
        age[index + 1] = age[index];
        index--;
    }
    name[index + 1] = new_name;
    age[index + 1] = new_age;
}