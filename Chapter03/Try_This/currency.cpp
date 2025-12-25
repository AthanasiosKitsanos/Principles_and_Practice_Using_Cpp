#include "headers.h"

int main()
{
    std::cout << "Enter a number and the type of currency you want to convert to the remaining type of currencies ( Yen/y, Kroner/k, Pounds/p )" << std::endl;
    int amount;
    char currency;
    std::cin >> amount >> currency;

    std::cout << "You entered " << amount;
    switch(currency)
    {
        case 'y':
            std::cout << " Yen" << std::endl;
            std::cout << amount << " Yen is " << amount * 0.07 << " kroner and " << amount * 0.005 << " pounds" << std::endl;
            break;
        
        case 'k':
            std::cout << " Kroner" << std::endl;
            std::cout << amount << " Kroner is " << amount * 14.64 << " Yen and " << amount * 0.07 << " pounds" << std::endl;
            break;
        
        case 'p':
            std::cout << " Pounds" << std::endl;
            std::cout << amount << " Pounds is " << amount * 13.61 << " kroner and " << amount * 199.14 << " Yen" << std::endl;
            break;
        
        default:
            std::cout << " " << currency << ". " << currency << " is not a currency I know of" << std::endl;
            break;
    }   

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}