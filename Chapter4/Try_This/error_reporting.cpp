#include "headers.h"

int area(int length, int width)
{
    return length * width; 
}

int framed_area(int x, int y)
{
    const int int_sub = 2;

    if(x - int_sub <= 0 || y - int_sub <= 0)
    {
        return -1;
    }

    return area(x- int_sub, y - int_sub);
}

int f(int x, int y, int z)
{
    int area1 = area(x, y);
    if(area1 <= 0)
    {
        std::cerr << "non-positive area"<< std::endl;
    }

    int area2 = framed_area(1,z);
    int area3 = framed_area(y, z);

    double ratio = static_cast<double>(area1) / area3;

    std::cout << "Area1: " << area1 << std::endl;
    std::cout << "Area2: " << area2 << std::endl;
    std::cout << "Area3: " << area3 << std::endl;
    std::cout << "Ratio: " << ratio << std::endl;

    return 0;
}

void test(int x, int y, int z)
{
    int area1 = area(x, y);
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);
    double ratio = static_cast<double>(area1) / area3;
}

int main()
{
    f(3, 3, 3);

    //Thowing an exception to see what happens if it not handled
    //throw std::runtime_error{"Some text"};
    
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}