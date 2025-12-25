#include "headers.h"

double ctof(double c)
{
    return c * 1.8 + 32;
}

double ftoc(double f)
{
    return (f - 32) / 1.8;
}

int main()
{
    std::cout << "Enter a number in Celsius to convert to Fahrenheit: ";
    double celsius = 0;
    std::cin >> celsius;

    double fahrenheit = ctof(celsius);
    std::cout << "Fahrenheit: " << fahrenheit << std::endl;

    std::cout << "Enter a number in Fahrenheit to convert to Celsius: ";
    std::cin >> fahrenheit;

    celsius = ftoc(fahrenheit);
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Celsius: " << celsius << std::endl;

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}