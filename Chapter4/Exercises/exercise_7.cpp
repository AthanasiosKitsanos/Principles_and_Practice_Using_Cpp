#include "headers.h"

double distinctive(int& a, int& b, int& c)
{
    if(a == 0)
    {
        throw std::overflow_error("Division by Zero is not allowed");
    }

    double d = pow(b, 2) - 4 * a * c;

    if(d < 0)
    {
        throw std::overflow_error("Destinctive is less than zero. There are no real root.");
    }

    std::cout << "Destinctive: " << d << std::endl;
    std::cout << "Square Root of Destinctive: " << sqrt(d) << std::endl;

    return d;
}

int main()
{
    std::cout << "Give three numbers to find the 'x' in a quadratic equation" << std::endl;
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    double d = 0;

    try
    {
        d = distinctive(a, b, c);
    }
    catch(std::overflow_error e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::fixed << std::setprecision(2);
    
    if(d > 0)
    {
        std::cout << "Destinctive is greater than zero. 'x' has two possible values" << std::endl;

        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);

        std::cout << "x = " << x1 << " or x = " << x2 << std::endl;

        //Checking if the two values are right. If the result is 0, then they are.
        std::cout << "Equation result with x = " << x1 << " is " << (a * pow(x1, 2)) + b * x1 + c << std::endl;
        std::cout << "Equation result with x = " << x2 << " is " << (a * pow(x2, 2)) + b * x2 + c << std::endl;
    }
    else
    {
        std::cout << "Destinctive is equal to zero. 'x' has one possible value" << std::endl;
        
        double x = -b / (2 * a);

        std::cout << "x = " << x << std::endl;

        //Checking if the value of x is right. If the result is 0, then it is.
        std::cout << "Equation result with x = " << x << " is " << (a * pow(x, 2)) + b * x + c << std::endl;
    }
    
    std::cout.unsetf(std::ios::fixed);
    
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}