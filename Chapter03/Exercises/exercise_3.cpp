#include "headers.h"

int main()
{
    std::vector<double> temps;
    for(double temp; std::cin >> temp;)
    {
        temps.push_back(temp);
    }
        
    double sum = 0;
    for (double x : temps)
    {
        sum += x;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average temperature: " << sum/temps.size() << '\n';

    std::sort(temps.begin(), temps.end());

    //This is where the intended mistake is fixed
    if(temps.size() % 2 == 1)
    {
        std::cout << "Median temperature: " << temps[temps.size() / 2] << std::endl;
    }
    else
    {
        std::cout << "Median temperature: " << (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2 << std::endl;
    }
    std::cout.unsetf(std::ios::fixed);
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}