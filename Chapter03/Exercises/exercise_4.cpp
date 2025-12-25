#include "headers.h"

int main()
{
    double sum = 0;
    std::vector<double> vec;

    std::cout << "Enter a sequence of distances. After entering as many as you like press 'i' to continue:" << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    for(double num; std::cin >> num;)
    {
        vec.push_back(num);
        sum += num;
    }
    std::cin.clear();

    std::cout << "Total distance: " << sum << std::endl;
    
    std::sort(vec.begin(), vec.end());

    std::cout << "Smallest distance: " << vec[0] << std::endl;
    std::cout << "Biggest distance: " << vec[vec.size() - 1] << std::endl;

    std::cout << "Mean distance between each neighboring city:" << std::endl;
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << i + 1 << ". " << vec[i] / 2 << std::endl;
    }

    std::cout.unsetf(std::ios::fixed);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}