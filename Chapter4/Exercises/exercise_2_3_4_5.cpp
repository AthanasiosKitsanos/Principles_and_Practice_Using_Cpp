#include "headers.h"

//The exercise has mistakes on purpose, the exercise is for me to correct them
double ctok(double c)
{
    //Exercise 4
    if(c < -273.15)
    {
        throw std::invalid_argument("Convertion from celsius to Kelvin failed. Input was lower than -273.15");
    }

    int k = c + 273.15;

    return k;
}

//Exercise 5
double ktoc(double k)
{
    if(k < 0)
    {
        throw std::invalid_argument("Conversion for Kelvin to celsius faild. Argument given was lower than 0");
    }

    int c = k - 273.15;

    return c;
}

int main()
{
    //Exercise 2
    double c = 0;
    double k = 0;

    std::cout << "Enter Celsuis: ";
    std::cin >> c; // it was d

    try
    {
        k = ctok(c); //it was "c"
        std::cout << "Kelvin Result: " << k << std::endl; // it was std::Cout
    }
    catch(std::invalid_argument e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Enter Kelvin: ";
    std::cin >> k;

    try
    {
        c = ktoc(k);
        std::cout << "Celsius Result: " << c << std::endl;
    }
    catch(std::invalid_argument e)
    {
        std::cerr << e.what() << std::endl;
    }

    //exercise 3
    // if(k < -273.25)
    // {
    //     std::cerr << k << " is less than absolute zero" << std::endl;
    // }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}