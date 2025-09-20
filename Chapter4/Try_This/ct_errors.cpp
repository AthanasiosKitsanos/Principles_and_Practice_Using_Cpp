#include "headers.h"

int area(int length, int width) { return length * width; }

//Testing compile time errors messages
int main()
{

    //Syntax errors
    // int s1 = area(7, 2;
    // int s2 = area(7, 2)
    // Int s3 = area(7, 2);
    // int s4 = area('7, 2);

    //Type errors
    // int x0 = arena(7, 2);
    // int x1 = area(7);
    // int x2 = area("seven", 2);

    //Logic errors
    // int x4 = area(10,−7);               OK: but what is a rectangle with a width of minus 7?
    // int x5 = area(10.7,9.3);            OK: but calls area(10,9)
    // char x6 = area(100,9999);           OK: but truncates the result

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}