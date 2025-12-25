#include "headers.h"

int main()
{
    //std::cout << "Enter 2 integer numbers or press 'I' to exit:" << std::endl;
    //int num1, num2;

    //Using double
    // double num1, num2;
    // std::cout << std::fixed << std::setprecision(2);

    // while(std::cin >> num1 >> num2)
    // {
    //     if(num1 > num2)
    //     {
    //         std::cout << "The smaller value is " << num2 << ". The larger value is " << num1 << std::endl;
    //     }
    //     else if(num1 < num2)
    //     {
    //         std::cout << "The smaller value is " << num1 << ". The larger value is " << num2 << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "The numbers are equal" << std::endl;
    //     }

    //     if(num1 - num2 <= 1.0 / 100 || num2 - num1 <= 1.0 / 100)
    //     {
    //         std::cout << "The numbers are almost equal" << std::endl;
    //     }
    // }

    // std::cout.unsetf(std::ios::fixed);

    // double num;
    // double smallest = 0;
    // double larger = 0;

    // std::cout << std::fixed << std::setprecision(2);
    // std::cout << "Enter a real number or press 'I' to exit:" << std::endl;

    // while(std::cin >> num)
    // {
    //     std::cout << "You entered " << num << std::endl;
    //     if(smallest == 0 && larger == 0)
    //     {
    //         smallest = num;
    //         larger = num;
    //     }

    //     if(num < smallest)
    //     {
    //         smallest = num;
    //     }

    //     if(num > larger)
    //     {
    //         larger = num;
    //     }

    //     std::cout << "The smallest so far: " << smallest << std::endl;
    //     std::cout << "The largest so far: " << larger << std::endl;
    // }

    // std::cout.unsetf(std::ios::fixed);

    std::cout << "Enter a real number and the type of length units (cm, in, ft, m):" << std::endl;
    double num;
    std::string unit;
    std::vector<double> vec;

    std::cout << std::fixed << std::setprecision(2);

    while(std::cin >> num >> unit)
    {
        std::cout << "\nYou entered " << num << unit << std::endl;

        if(unit == "cm")
        {
            std::cout << "In meters: " << num / 100 << "m" << std::endl;
            std::cout << "In inches: " <<  num * 2.54 << "in" << std::endl;
            std::cout << "In feet: " << num / 100 * 3 << "ft" << std::endl;

            vec.push_back(num / 100);
        }
        else if(unit == "in")
        {
            std::cout << "In centimeters: " << num * 2.54 << "cm" << std::endl;
            std::cout << "In meters: " << (num * 2.54) / 100 << "m" << std::endl;
            std::cout << "In feet: " << num * 12 << "ft" << std::endl;

            vec.push_back((num * 2.54) / 100);
        }
        else if(unit == "ft")
        {
            std::cout << "In meters: " << num / 3 << "m" << std::endl;
            std::cout << "In centimeters: " << (num / 3) * 100 << "cm" << std::endl;
            std::cout << "In inches: " << num * 12 << "in" << std::endl;

            vec.push_back(num / 3);
        }
        else if(unit == "m")
        {
            std::cout << "In centimeters: " << num * 100 << "cm" << std::endl;
            std::cout << "In inches: " << (num * 100) / 2.54 << "in" << std::endl;
            std::cout << "In feet " << num / 3 << "ft" << std::endl;

            vec.push_back(num);
        }
        else
        {
            std::cout << "I don't know about that unit of measurement" << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    if(!vec.empty())
    {
        std::sort(vec.begin(), vec.end());

        double sum;

        for(int i = 0; i < vec.size(); i++)
        {   
            sum += vec[i];
            std::cout << i + 1 << ". " << vec[i] << std::endl;
        }

        std::cout << "\nSmallest: " << vec[0] << std::endl;
        std::cout << "Largest: " << vec[vec.size() - 1] << std::endl;
        std::cout << "Total values: " << vec.size() << std::endl;
        std::cout << "Sum of values: " << sum << " in meters" << std::endl;
    }

    std::cin.clear(); // To clear fail state after exiting the while loop
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}