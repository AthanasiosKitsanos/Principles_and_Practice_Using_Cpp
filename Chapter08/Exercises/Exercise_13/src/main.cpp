#include "pch/pch.h"
#include "models/rational.h"
#include <termination>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    models::rational rat1{4, 12};
    std::cout << "Before: " << rat1 << '\n';
    std::cout << "After: " << rat1 << '\n';
    models::rational rat2{2, 10};
    // Assignement
    rat1 = rat2;
    std::cout << "Rat 1: " << rat1 << '\n';
    std::cout << "Rat 2: " << rat2 << '\n';
    // += operator
    rat1 += rat1;
    std::cout << "rat1 += rat1: " << rat1 << '\n';
    std::cout << "rat1 simpified: " << rat1 << '\n';
    std::cout << "rat1 as double: " << rat1.approximate() << '\n';
    // = operator while creating a new object
    models::rational rat3{rat1 + rat2};
    std::cout << "Rat 3: " << rat3 << '\n';
    std::cout << "rat3 simpified: " << rat3 << '\n';
    std::cout << "rat3 as double: " << rat3.approximate() << '\n';
    // / operator
    rat3 = rat1 / rat2;
    std::cout << "rat3 = rat1 / rat2: " << rat3 << '\n';
    // /= operator
    rat3 /= rat3;
    std::cout << "rat3 /= rat3: " << rat3 << '\n';
    // *= operator
    rat1 *= rat2;
    std::cout << "rat1 *= rat2: " << rat1 << '\n';
    // * operator
    rat2 = rat1 * rat3;
    std::cout << "rat2 = rat1 * rat3 : " << rat2 << '\n';
    std::cout << "rat1 == rat2: " << (rat1 == rat2 ? "True\n" : "False\n"); 
    termination_prompt();
}

// Rationals are used for accurate representation of floating point or double numbers