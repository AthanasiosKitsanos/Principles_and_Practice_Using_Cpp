#include "headers.h"

int main()
{
    std::cout << "Enter you name of the person you want to write to: ";
    std::string first_name;
    std::getline(std::cin, first_name);

    std::cout << "Enter a friend's name: ";
    std::string friend_name;
    std::getline(std::cin, friend_name);

    std::cout << "Enter the age of the recipient: ";
    int age;
    std::cin >> age;

    std::cout << "Hello " << first_name << "," << std::endl;
    std::cout << "How are you?";
    std::cout << "I'm fine. I miss you" << std::endl;
    std::cout << "Have you seen " << friend_name << " lately?" << std::endl;
    std::cout << "I hear you just had your birthday and you are " << age << " years old." << std::endl;

    if(age == 0)
    {
        std::cout << "You are kidding" << std::endl;
    }

    if(age < 12)
    {
        std::cout << "Next year you will be " << age + 1 << "." << std::endl;
    }
    else if(age == 17)
    {
        std::cout << "Next year you will be able to vote," << std::endl;
    }
    else if(age == 70)
    {
        std::cout << "Are you retired?" << std::endl;
    }

    std::cout << "Your's sincerely,\n" << "(Here goes the signature)\n" << "Athanasios" << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}