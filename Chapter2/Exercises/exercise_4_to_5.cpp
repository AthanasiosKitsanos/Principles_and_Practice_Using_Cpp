#include "headers.h"

int main()
{
    std::cout << "Enter two intigers: ";
    int val1, val2;
    std::cin >> val1 >> val2;

    if(val1 > val2)
    {
        std::cout << "Smaller: " << val2 << ", Larger: " << val1 << std::endl;
    }
    else
    {
        std::cout << "Smaller: " << val1 << ", Larger: " << val2 << std::endl;
    }

    std::cout << "Sum: " << val1 + val2 << std::endl;
    std::cout << "Difference: " << (val1 > val2 ? val1 - val2 : val2 - val1) << std::endl;
    std::cout << "Product: " << val1 * val2 << std::endl;
    std::cout << "Ratio: " << (val1 > val2 ? val1/val2 : val2/val1) << std::endl;


    //Exercise 5 that is a modification of the previous one
    std::cout << "Enter two floating-point numbers: ";
    double val3, val4;
    std::cin >> val3 >> val4;

    if(val3 > val4)
    {
        std::cout << "Smaller: " << val4 << ", Larger: " << val3 << std::endl;
    }
    else
    {
        std::cout << "Smaller: " << val3 << ", Larger: " << val4 << std::endl;
    }

    std::cout << "Sum: " << val3 + val4 << std::endl;
    std::cout << "Difference: " << (val3 > val4 ? val3 - val4 : val4 - val3) << std::endl;
    std::cout << "Product: " << val3 * val4 << std::endl;
    std::cout << "Ratio: " << (val3 > val4 ? val3/val4 : val4/val3) << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}