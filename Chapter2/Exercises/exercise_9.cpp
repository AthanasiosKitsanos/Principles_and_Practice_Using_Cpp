#include "headers.h"

int main()
{
    std::cout << "Write a number form zero to four:" << std::endl;
    std::string number;
    std::getline(std::cin, number);

    for(char& c: number)
    {
        c = std::tolower(static_cast<unsigned char>(c));
    }

    if(number == "zero")
    {
        std::cout << "You wrote " << number << ": " << 0 <<std::endl;
    }
    else if(number == "one")
    {
        std::cout << "You wrote " << number << ": " << 1 <<std::endl;
    }
    else if(number == "two")
    {
        std::cout << "You wrote " << number << ": " << 2 <<std::endl;
    }
    else if(number == "three")
    {
        std::cout << "You wrote " << number << ": " << 3 <<std::endl;
    }
    else if(number == "four")
    {
        std::cout << "You wrote " << number << ": " << 4 <<std::endl;
    }
    else
    {
        std::cout << "Not a number I know" <<std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}