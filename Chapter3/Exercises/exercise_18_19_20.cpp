#include "headers.h"

int main()
{
    std::cout << "Exercise 18" << std::endl;

    std::vector<std::string> names;
    std::vector<int> scores;

    std::string name = "";
    int score = 0;

    std::cout << "Enter a name and a score. To terminate the loop enter NoName as the name and 0 to score" << std::endl;

    while(true)
    {
        std::cout << "Name: ";
        std::getline(std::cin, name);
        
        std::cout << "Score: ";
        std::cin >> score;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if((name == "NoName" || name == "noname") && score == 0)
        {
            break;
        }

        for(int i = 0; i < names.size(); i++)
        {
            if(name == names[i])
            {
                std::cout << "Name already exists" << std::endl;
                continue;
            }
        }

        names.push_back(name);
        scores.push_back(score);

        std::cout << std::endl;  
    }

    std::cout << std::endl;

    for(int i = 0; i < names.size(); i++)
    {
        std::cout << "Name: " << names[i] << '\t' << "Score: " << scores[i] << std::endl;
    }

    std::cout << "\nExercise 19" << std::endl;
    std::cout <<"Enter a name to get that person's score or enter exit to terminate the loop" << std::endl;

    for(;std::getline(std::cin, name);)
    {
        if(name == "exit")
        {
            break;
        }

        bool found = false;

        for(int i = 0; i < names.size(); i++)
        {
            if(name == names[i])
            {
                std::cout << name << "'s score: " << scores[i] << std::endl;
                found = true;
                break;
            }
        }

        if(!found)
        {
            std::cout << "Name not found\n" << std::endl;
        }
    }

    std::cout << "Exercise 20" << std::endl;
    std::cout << "Enter a score to find all names with that score or press any other key to terminate the loop" << std::endl;

    for(;std::cin >> score;)
    {
        bool found = false;

        for(int i = 0; i < scores.size(); i++)
        {
            if(score == scores[i])
            {
                std::cout << names[i] << std::endl;
                found = true;
            }
        }

        if(!found)
        {
            std::cout << "There is no one with score: "<< score << '\n' << std::endl;
        }
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}