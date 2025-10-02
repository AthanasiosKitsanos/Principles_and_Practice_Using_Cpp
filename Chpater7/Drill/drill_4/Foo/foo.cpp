#include "foo.h"

int foo = 0;

void print_foo()
{
    std::cout << "foo = " << foo << std::endl;
}

void print(const int& x)
{
    std::cout << "x = " << x << std::endl;
    std::cout << "Press any key to exit...";
    std::cin.get();
}