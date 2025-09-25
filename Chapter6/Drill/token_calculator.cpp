#include "headers.h"
#include "token.h"
#include "token_stream.h"
#include "global.h"
#include "variable.h"

int main() 
{
    try
    {
        initialize_stream_pointer();

        ts_global->define_name("pi", 3.1415926535);
        ts_global->define_name("e", 2.7182818284);
        ts_global->define_function("pow", Variable{"x", 0});
        ts_global->define_function("sqrt", Variable{"x", 0});
        
        calculate();
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete_stream_pointer();

    std::cin.clear();
    std::cout << "Press any key to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}