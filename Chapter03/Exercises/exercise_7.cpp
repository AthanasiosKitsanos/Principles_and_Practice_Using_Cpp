#include "headers.h"

int main()
{
    std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    std::cout << "Enter a value between 0 and 9 or press any other key to continue:" << std::endl;

    for(int num; std::cin >> num;)
    {
        if(num < 0 || num  > 9)
        {
            std::cout << "Input out of bounds, try again:" << std::endl;
            continue;
        }

        for(int i = 0; i < numbers.size(); i++)
        {
            if(i == num)
            {
                std::cout << "You entered: " << num << '\t' << numbers[i] << std::endl;
                break;
            }
        }
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter a value between 'zero' and 'nine' or write 'exit' to continue:" << std::endl;

    for(std::string input; std::getline(std::cin, input);)
    {
        if(input == "exit")
        {
            std::cout << "Input loop termnated" << std::endl;
            break;
        }

        for(int i = 0; i < numbers.size(); i++)
        {
            if(input == numbers[i])
            {
                std::cout << "You wrote: " << numbers[i] << " " << i << std::endl;
                break;
            }

            if(i == 9)
            {
                std::cout << "No such number found" << std::endl;
            }
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}