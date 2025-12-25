#include "headers.h"

int main()
{
    std::cout << "Using a while loop" << std::endl;
    char c = 'a';
    while(c <= 'z')
    {
        std::cout << c << '\t' << int(c) << std::endl;
        c += 1;
    }

    std::cout << '\n' << "Using a for loop" << std::endl;

    for(char c = 'a'; c <= 'z'; c++)
    {
        std::cout << c << '\t' << int(c) << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}