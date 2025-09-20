#include "headers.h"
#include "name_value.h"

int main()
{
    std::vector<Name_Value> vector;

    std::cout << "Enter a name and a score. To terminate the loop enter NoName as the name and 0 to score" << std::endl;

    std::string name = "";
    int score = 0;

    while(std::cin >> name >> score)
    {
        if((name == "NoName" || name == "noname") && score == 0)
        {
            break;
        }

        for(int i = 0; i < vector.size(); i++)
        {
            if(name == vector[i].name)
            {
                std::cout << "Name already exists" << std::endl;
            }
        }

        vector.push_back(Name_Value{name, score});

        std::cout << std::endl;
    }

    for(int i = 0; i < vector.size(); i ++)
    {
        std::cout << "Name: " << vector[i].name << '\t' << "Score: " << vector[i].score << std::endl;
    }

    std::cout <<"Enter a name to get that person's score or enter exit to terminate the loop" << std::endl;

    while(std::cin >> name)
    {
        if(name == "exit")
        {
            break;
        }

        bool found = false;

        for(int i = 0; i < vector.size(); i++)
        {
            if(name == vector[i].name)
            {
                std::cout << vector[i].name << "'s score: " << vector[i].score << std::endl;
                found = true;
                break;
            }
        }

        if(!found)
        {
            std::cout << "Name not found" << std::endl;
        }
    }

    std::cout << "Enter a score to find all names with that score or press any other key to terminate the loop" << std::endl;

    while(std::cin >> score)
    {
        bool found = false;

        for(int i = 0; i < vector.size(); i++)
        {
            if(score == vector[i].score)
            {
                std::cout << vector[i].name << std::endl;
                found = true;
            }
        }

        if(!found)
        {
            std::cout << "There is no one with such score: " << score << std::endl;
        }
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit..." << std::endl;
    std::cin.get();

    return 0;
}