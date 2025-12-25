#include "headers.h"

int main()
{   
    std::cout << "Think and enter a number between 1 and 100:" << std::endl;
    int num;

    while(true)
    {    
        std::cin >> num;

        if(num > 0 && num <= 100)
        {
            break;
        }

        std::cout << "Number out of bounds. Try again:" << std::endl;
    }

    int smaller = 1;
    int larger = 100;

    for(int i = 1; i <= 7; i++)
    {
        int guess = (larger + smaller) / 2;

        std::cout << "\nTry " << i << "." << std::endl;
        std::cout << "Is the number less than " << guess << " (y/n);" << std::endl;
        
        char ch;
        for(;std::cin.get(ch);)
        {
            if(ch == 'y' || ch == 'n')
            {
                break;
            }

            std::cout << "Enter 'y' or 'n':" << std::endl;
        }
        
        if(ch == 'y')
        {
            larger = guess - 1;
            //smaller = (guess + smaller) / 2;
        }
        else if(ch == 'n')
        {
            smaller = guess + 1;
        }

        if(guess == num)
        {
            std::cout << "Your number is " << guess << std::endl;
            std::cout << "Found it in " << i << (i == 1 ? " try" : " tries") << std::endl;
            break;
        }

        if(i == 7)
        {
            std::cout << "I used all my tries" << std::endl;
        }
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}