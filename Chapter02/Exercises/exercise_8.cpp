#include "headers.h"

int main()
{
    std::cout << "Enter a number and find if it's an odd or even number" << std::endl;
    int number;
    std::cin >> number;

    if(number % 2 == 0)
    {
        std::cout << "The valye " << number << " is an even number" << std::endl;
    }
    else
    {
        std::cout << "The valye " << number << " is an odd number" << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}