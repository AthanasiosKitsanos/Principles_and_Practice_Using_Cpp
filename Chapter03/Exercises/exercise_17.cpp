#include "headers.h"

int main()
{   
    std::cout <<"Let's find 'x' in a classic quadratic equation a*x^2 + b*x + c" << std::endl;

    std::cout << "Enter 3 intiger numbers: (1st number can not be 0) or press any other key to terminate the loop" << std::endl;

    for(double a, b, c; std::cin >> a >> b >> c;)
    {
        if(a == 0)
        {
            std::cout << "First input can not be zero" << std::endl;
        }

        double d = pow(b, 2) - 4 * a * c;

        if(d > 0)
        {
            std::cout << "Since D is greater than 0, there are two possible values for x" << std::endl;
            std:: cout << "x = " << (-b + sqrt(d)) / (2 * a) << " or x = " << (-b - sqrt(d)) / (2 * a) << std::endl;
        }
        else if(d == 0)
        {
            std::cout << "Since D is equal to 0, there is onw double solution" << std::endl;
            std::cout << "x = " << -b / (2 * a) << std::endl;
        }
        else
        {
            std::complex<double> d_complex = pow(b, 2) - std::complex<double>(4 * a * c, 0);
            std::cout << "Since D is less than 0, it has 2 complex solutions" << std::endl;
            std::cout << "x = " << (-b + sqrt(d_complex)) / (2 * a) << " or x = " << (-b - sqrt(d_complex)) / (2 * a) << std::endl;
        }

        std::cout << "Enter 3 intiger numbers: (1st number can not be 0) or press any other key to terminate the loop" << std::endl;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}