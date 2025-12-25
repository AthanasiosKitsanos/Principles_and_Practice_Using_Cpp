#include "headers.h"

int main()
{
    char operation;

    std::cout << "EXERCISE 6" << std::endl;
    std::cout << "Enter 2 values and an operation (+, -, /, *)" << std::endl;

    for(double num1, num2; std::cin >> num1 >> operation >> num2;)
    {
        switch(operation)
        {
            case '+':
                std::cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << std::endl;
                break;

            case '-':
                std::cout << "The sub of " << num1 << " and " << num2 << " is " << num1 - num2 << std::endl;
                break;

            case '/':
                if(num2 == 0)
                {
                    std::cout << "Division by zero is not allowed" << std::endl;
                }
                else
                {
                    std::cout << "The div of " << num1 << " and " << num2 << " is " << num1 / num2 << std::endl;
                }
                break;

            case '*':
                std::cout << "The mul of " << num1 << " and " << num2 << " is " << num1 * num2 << std::endl;
                break;

            default:
                std::cout << "Not an operation I know" << std::endl;
                break;
        }
    }
    
    std::cin.clear();

    std::cout << "EXERCISE 8" << std::endl;
    std::cout << "Enter 2 single digit form 0 (zero) to 9 (nine) values and an operation (+, -, /, *) or press exit to terminate the loop:" << std::endl;
    std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(std::string input; std::getline(std::cin, input);)
    {
        if(input.empty())
        {
            continue;
        }

        if(input == "exit")
        {
            std::cout << "Loop is terminated." << std::endl;
            break;
        }

        int op_position = input.find_first_of("+-/*");

        if(op_position == std::string::npos)
        {
            std::cout << "Not an operation I know" << std::endl;
            continue;
        }

        std::string num1 = input.substr(0, op_position);
        operation = input[op_position];
        std::string num2 = input.substr(op_position + 1, input.length() - 1);

        num1.erase(remove_if(num1.begin(), num1.end(), ::isspace), num1.end());
        num2.erase(remove_if(num2.begin(), num2.end(), ::isspace), num2.end());

        if(num1 == "exit" || num2 == "exit")
        {
            std::cout << "Loop terminated." << std::endl;
            break;
        }

        int number1 = -1;
        int number2 = -1;

        for(int i = 0; i < numbers.size(); i++)
        {
            if(num1 == numbers[i] || num1 == std::to_string(i))
            {
                number1 = i;
            }

            if(num2 == numbers[i] || num2 == std::to_string(i))
            {
                number2 = i;
            }
        }

        if(number1 == -1 || number2 == -1)
        {
            std::cout << "Input out of bounds. Please try again:" << std::endl;
            continue;
        }

        switch(operation)
        {
            case '+':
                std::cout << "The sum of " << number1 << " and " << number2 << " is " << number1 + number2 << std::endl;
                break;

            case '-':
                std::cout << "The sub of " << number1 << " and " << number2 << " is " << number1 - number2 << std::endl;
                break;

            case '/':
                if(number2 == 0)
                {
                    std::cout << "Division by zero is not allowed" << std::endl;
                }
                else
                {
                    std::cout << "The div of " << number1 << " and " << number2 << " is " << number1 / number2 << std::endl;
                }
                break;

            case '*':
                std::cout << "The mul of " << number1 << " and " << number2 << " is " << number1 * number2 << std::endl;
                break;
        }
    }
    
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}