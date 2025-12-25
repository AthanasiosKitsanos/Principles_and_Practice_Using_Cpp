#include "headers.h"

int main()
{
    
    int previous = 0;
    int current = 1;
    int sum = 0;

    for(int i = 0; i <= std::numeric_limits<int>::max() - 2; i++)
    {
        std::cout << current << std::endl;
        
        if(std::numeric_limits<int>::max() - current < previous)
        {
            std::cout << "The biggest Fibonacci number that fits on an int type is: " << sum << std::endl;
            break;
        }

        sum = current + previous;
        previous = current;
        current = sum;
    }
    
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}