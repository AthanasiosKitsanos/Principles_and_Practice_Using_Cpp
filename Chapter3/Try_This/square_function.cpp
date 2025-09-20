#include "headers.h"

//Creating a square function without returning num * num
int square(int num)
{
    int result = 0;
    for(int i = 0; i < num; i ++)
    {
        result += num;
    }

    return result;
}

int main()
{
    std::cout << "Result: " << square(2) << std::endl;
    std::cout << "Result: " << square(3) << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}