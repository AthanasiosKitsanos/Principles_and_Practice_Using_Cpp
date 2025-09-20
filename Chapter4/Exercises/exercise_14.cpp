#include "headers.h"

int count = 0;

bool normalized(std::string& day)
{
    std::string lower = "";

    for(char ch: day)
    {
        lower += tolower(ch);
    }

    static std::map<std::string, std::string> synonyms = 
    {
        {"mon", "Monday"},
        {"monday", "Monday"},
        {"Monday", "Monday"},
        {"tue", "Tuesday"},
        {"tuesday", "Tuesday"},
        {"Tuesday", "Tuesday"},
        {"wed", "Wednesday"},
        {"wednesday", "Wednesday"},
        {"Wednesday", "Wednesday"},
        {"thu", "Thursday"},
        {"thursday", "Thursday"},
        {"Thursday", "Thursday"},
        {"fri", "Friday"},
        {"friday", "Friday"},
        {"Friday", "Friday"},
        {"sat", "Saturday"},
        {"saturday", "Saturday"},
        {"Saturday", "Saturday"},
        {"sun", "Sunday"},
        {"sunday", "Sunday"},
        {"Sunday", "Sunday"}
    };

    if(synonyms.count(lower))
    {
        day = synonyms[lower];
        return true;
    }

    count++;
    std::cout << "Invalid day" << std::endl;

    return false;
}

int main()
{   
    std::unordered_map<std::string, int> day_value;
    std::vector<int> values;

    std::string day = "";
    int value = 0;
    int counter = 0;
    
    std::cout << "Enter a day of the week and a integer value (Write exit to stop the input)" << std::endl;

    for(int i = 0; i < 7 && std::cin >> day; i++)
    {
        if(!(std::cin >> value))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }

        if(day == "exit" && value == 0)
        {
            break;
        }

        if(!(normalized(day)))
        {
            i--;
            continue;
        }

        day_value.emplace(day, value);
        values.push_back(value);
    }

    int unordered_sum = 0;
    int values_sum = 0;

    int i = 0;

    for(std::pair<std::string, int> p: day_value)
    {
        unordered_sum += p.second;
        values_sum += values[i];
        i++;
    }


    std::cout << "Pairs sum: " << unordered_sum << std::endl;
    std::cout << "Values sum: " << values_sum << std::endl;


    if(count > 0)
    {
        std::cout << "Number of rejected values: " << count << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}