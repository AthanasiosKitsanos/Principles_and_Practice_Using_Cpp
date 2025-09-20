#include "headers.h"

int main()
{
    std::cout << "Enter the number of miles you want to convert into kilometers: ";
    int miles;
    std::cin >> miles;

    std::cout << "The miles you entered are converted to " << miles * 1609 << " kilometers." << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}