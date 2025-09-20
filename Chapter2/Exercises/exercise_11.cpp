#include "headers.h"

int main()
{
    int total = 0;

    std::cout << "How meny pennies do you have? ";
    int pennies;
    std::cin >> pennies;
    total += pennies;

    std::cout << "\nHow many nickels do you have? ";
    int nickels;
    std::cin >> nickels;
    total += nickels * 5;

    std::cout << "\nHow many dimes do you have? ";
    int dimes;
    std::cin >> dimes;
    total += dimes * 10;

    std::cout << "\nHow many quarters do you have? ";
    int quarters;
    std::cin >> quarters;
    total += quarters * 25;

    std::cout << "\nHow many half-dollar coins do you have? ";
    int half_dollars;
    std::cin >> half_dollars;
    total += half_dollars * 50;

    std::cout << "\nHow many one-dollar coins do you have? ";
    int one_dollars;
    std::cin >> one_dollars;
    total += one_dollars * 100;

    std::cout << "You have " << pennies << (pennies == 1 ? " penny" : " pennies") << std::endl;
    std::cout << "You have " << dimes << (dimes == 1 ? " dime" : " dimes") << std::endl;
    std::cout << "You have " << quarters << (quarters == 1 ? " quarter" : " quarters") << std::endl;
    std::cout << "You have " << half_dollars << " half-dollar " << (half_dollars == 1 ? "coin" : "coins") << std::endl;
    std::cout << "You have " << one_dollars << " one-dollar " << (one_dollars == 1 ? "coin" : "coins") << std::endl;
    std::cout << "You have a total of " << total << " pennies" << std::endl;
    std::cout << "In total you have " << total / 100 << " dollars and " << total % 100 << " cents" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}