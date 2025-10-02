#include "headers.h"
#include "global.h"

int main() 
{
    
    try
    {
        sym_table.define_name("pi", 3.1415926535, 1);
        sym_table.define_name("e", 2.7182818284, 1);
        
        calculate(ts_global);
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cin.clear();
    std::cout << "Press any key to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}