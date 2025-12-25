#include "headers.h"
#include "global.h"

void fibonacci(int x, int y, std::vector<int>& vec, int n)
{
    vec = std::vector<int>(n);

    vec[0] = x;
    vec[1] = y;

    std::cout << "Fibonacci Numbers: { ";

    for(int i = 0; i < vec.size(); ++i)
    {
        if(i == 0 || i == 1)
        {
            std::cout << vec[i] << ", ";
            continue;
        }

        vec[i] = vec[i - 1] + vec[i - 2];

        std::cout << vec[i];;

        if(i == vec.size() - 1)
        {
            std::cout << " }" << std::endl;
            return;
        }

        std::cout << ", ";
    }
}

void input_manager(int& x, int& y, int& size)
{
    std::cout << "Enter three integer numbers (press any other key to exit the loop):" << std::endl;
    if(!(std::cin >> x >> y >> size))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
        
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void run()
{
    std::vector<int> fib;

    int x;
    int y;
    int size;

    input_manager(x, y, size);

    fibonacci(3, 5, fib, 5);
}