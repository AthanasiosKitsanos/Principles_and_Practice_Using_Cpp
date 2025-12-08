#include "year/year.h"

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    year yr{};
    std::cin >> yr;
    if(std::cin.fail())
    {
        std::cout << "Failed to create instance" << std::endl;
        std::cin.clear();
    }
    else std::cout << yr << std::endl;
}