#include "headers.h"

int main()
{
    std::cout << "Enter a word: " << std::endl;
    std::string input;
    std::getline(std::cin, input);

    for(char c: input)
    {
        std::cout << c << '\t' << " in ASCII: " << int(c) << std::endl;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}