#include "headers.h"
#include "fibonacci.h"
#include <limits>

int main()
{
        
    std::cout << "Max fibonacci number: " << fibonacci() << std::endl;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    termination_prompt();

    return 0;
}