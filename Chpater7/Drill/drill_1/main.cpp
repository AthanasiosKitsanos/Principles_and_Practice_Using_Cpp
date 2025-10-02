#include <iostream>

void swap_v(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int& a, const int& b)// it would never change, and this function throws a compiler error of trying to swap const variables
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    // replace ? by v, r, or cr
    int x = 7;
    int y = 9;
    swap_r(x,y); //works with v, r
    swap_cr(7,9);  // works only with cr. no values are swapped
    const int cx = 7;
    const int cy = 9;
    swap_v(cx,cy); // works only with cr, but it doesnt change the values
    swap_cr(7.7,9.9); // works with r and cr. cr doesnt change values
    double dx = 7.7;
    double dy = 9.9;
    swap_cr(dx,dy); // works with everything, except cr
    swap_v(7.7,9.9); // works only with cr, but the values can not change

    std::cout << x << '\t' << y << std::endl;
    std::cout << cx << '\t' << cy << std::endl;
    std::cout << dx << '\t' << dy << std::endl;
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}