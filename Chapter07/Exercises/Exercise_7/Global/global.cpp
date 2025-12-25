#include "global.h"

void print_elements(const std::vector<std::string>& names, const std::vector<double>& age)
{
    std::cout << std::endl;
    for(int i = 0; i < names.size(); i++)
    {
        std::cout << names[i] << '\t' << age[i] << std::endl;
    }
}

bool is_valid_age(const double& age)
{
    if(age > 100 || age < 0) return false;

    return true;
}

double get_age()
{
    double age;

    if(!(std::cin >> age))
    {
        throw TerminationException("Termination Requested");
    }

    if(!is_valid_age(age)) throw std::out_of_range("Input out of Bounds (Try for 0 to 100)");

    return age;
}

void fill_age_vector(std::vector<double>& age, const std::vector<std::string>& names)
{   
    double p_age = 0;

    for(int i = 0; i < names.size(); i++)
    {
        std::cout << "Enter the age of " << names[i] << ": ";

        while(true)
        {
            try
            {
                p_age = get_age();

                age.push_back(p_age);

                break;
            }
            catch(std::out_of_range& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
}

std::vector<std::string> sort_names_vector(std::vector<std::string> names)
{
    std::string current_name = "";

    for(int i = 0; i < names.size() - 1; i++)
    {
        for(int j = i + 1; j < names.size(); j++)
        {
            if(names[i] > names[j])
            {
                current_name = names[i];
                names[i] = names[j];
                names[j] = current_name;
            }
        }
    }

    return names;
}

std::vector<double> order_age_by_name(const std::vector<std::string>& string_vector, const std::vector<std::string>& sorted_string_vector, const std::vector<double>& age)
{
    std::vector<double> order_age_vector;

    for(int i = 0; i < sorted_string_vector.size(); i++)
    {
        for(int j = 0; j < string_vector.size(); j++)
        {
            if(sorted_string_vector[i] == string_vector[j])
            {
                order_age_vector.push_back(age[j]);
                break;
            }
        }
    }

    return order_age_vector;
}

void run()
{
    std::vector<std::string> names = { "Elena", "Diego", "Carla", "Boris", "Alice" };
    std::vector<double> age;

    try
    {
        fill_age_vector(age, names);

        print_elements(names, age);

        std::vector<std::string> sorted_names_vector = sort_names_vector(names);

        std::vector<double> sorted_age_vector = order_age_by_name(names, sorted_names_vector, age);

        print_elements(sorted_names_vector, sorted_age_vector);
    }
    catch(TerminationException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    termination_prompt();
}