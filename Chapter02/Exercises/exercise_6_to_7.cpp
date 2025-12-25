#include "headers.h"

int main()
{
    std::cout << "Enter 3 integer numbers:" << std::endl;

    int array[3];

    for(int i = 0; i < 3; i++)
    {
        int num;
        std::cin >> num;
        array[i] = num;
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                int current = array[j];
                array[j] = array[j + 1];
                array[j + 1] = current;
            }
        }
    }
    

    for(int i = 0; i < 3; i++)
    {
        std::cout << array[i];

        if(i != 2)
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //Exercise 7 is an extention of the above
    std::cout << "Enter three names:" << std::endl;
    std::string names[3];

    for(int i = 0; i < 3; i++)
    {
        std::string name;
        std::getline(std::cin, name);
        names[i] = name;
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2 - i; j++)
        {
            if(names[j] > names[j + 1])
            {
                std::string current = names[j];
                names[j] = names[j + 1];
                names[j + 1] = current;
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        std::cout << names[i];

        if(i != 2)
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}