#include "headers.h"

int main()
{
    std::cout << "Please enter an integer number of values you want to sum: ";
    
    {
        long long input = 0;

        std::cin >> input;

        try
        {
            if(input < 0 || input > std::numeric_limits<int>::max())
            {
                throw std::out_of_range("The number you entered is too big, or less than 0");
            }

            int n = static_cast<int>(input);

            std::vector<int> int_vector;

            std::cout << "Enter some numbers and some will be summarized based on your previous input (Press 'I' to exit)" << std::endl;

            for(int value; std::cin >> value;)
            {
                int_vector.push_back(value);
            }

            std::cin.clear();

            if(n > int_vector.size())
            {
                throw std::out_of_range("The count of numbers you want to summarize are less");
            }

            int int_sum = 0;
            long long sum = 0;

            for(int i = 0; i < int_vector.size(); i++)
            {
                sum += int_vector[i];
            }

            if(sum > std::numeric_limits<int>::max())
            {
                throw std::out_of_range("The sum is too big to summarize");
            }

            int_sum = static_cast<int>(sum);

            std::cout << "The sum of " << n << " first numbers is: " << sum << std::endl;
        }
        catch(std::out_of_range e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter a double number of values you want to sum: ";

    double input = 0;
    std::cin >> input;

    try
    {
        if(input < 0)
        {
            throw std::out_of_range("The number you entered is too big, or less than 0");
        }

        std::vector<double> double_vector;

        std::cout << "Enter some numbers and some will be summarized based on your previous input (Press 'I' to exit)" << std::endl;

        for(double value; std::cin >> value;)
        {
            double_vector.push_back(value);
        }

        std::cin.clear();

        if(input > double_vector.size())
        {
            throw std::out_of_range("The count of numbers you want to summarize are less");
        }

        std::vector<double> def_vector;

        for(int i = 1; i < input; i++)
        {
            def_vector.push_back(double_vector[i] - double_vector[i - 1]);
        }

        for(int i = 0; i < def_vector.size(); i++) // since the size of double_vector is 2 times bigger than the def_vector
        {
            std::cout << double_vector[i + 1] << " - " << double_vector[i] << " = " << def_vector[i] << std::endl;
        }
    }
    catch(std::out_of_range e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}