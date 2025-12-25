#include "headers.h"

int main()
{
    std::vector<std::string> string_list;

    std::cout << "Enter a word or press enter to exit the loop:" << std::endl;
    for(std::string word; std::getline(std::cin, word);)
    {
        if(word == "" || word == "\n")
        {
            break;
        }

        string_list.push_back(word);
    }

    for(std::string word: string_list)
    {
        if(word == "brocoli")
        {
            std::cout << "bleep" << std::endl;
        }
        else
        {
            std::cout << word << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}