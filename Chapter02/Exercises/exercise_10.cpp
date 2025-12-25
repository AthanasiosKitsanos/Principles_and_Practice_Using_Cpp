#include "headers.h"

int main()
{
    std::cout << "Enter two floating point numbers:" << std:: endl;
    double num1, num2;
    std::cin >> num1 >> num2;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter what operation you wan to excecute (+, -, /, *):" << std::endl;
    std::string operation;
    std::getline(std::cin, operation);

    std::cout << std::fixed << std:: setprecision(2);
    std::cout << operation << " " << num1 << " " << num2 << std::endl;

    if(operation == "+" || operation == "plus")
    {
        int sum = num1 + num2;
        std::cout << num1 << " " << operation << " " << num2 << " = " << sum << std::endl;
    }

    if(operation == "-" || operation == "minus")
    {
        std::cout << num1 << " " << operation << " " << num2 << " = " << (num1 - num2 < 0 ? (num1 - num2) * (-1) : num1 - num2) << std::endl;
    }

    if(operation == "/" || operation == "div")
    {
        std::cout << num1 << " " << operation << " " << num2 << " = " << num1 / num2 << std::endl;
    }

    if(operation == "*" || operation == "mul")
    {
        std::cout << num1 << " " << operation << " " << num2 << " = " << num1 * num2 << std::endl;
    }

    std::cout.unsetf(std::ios::fixed);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}