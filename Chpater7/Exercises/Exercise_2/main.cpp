#include "headers.h"

void print(const std::string& label, std::vector<int>& v)
{
    std::cout << label << " { ";
    
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];

        if(i == v.size() - 1)
        {
            std::cout << " }" << std::endl;
            return;
        }

        std::cout << ", ";
    }
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    print("Numbers", vec);

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}