#include "headers.h"
#include "token.h"
#include "token_stream.h"

int main() 
{
    initialize_stream_pointer();
        
    try
    {
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

        calculate();
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    delete_stream_pointer();

    return 0;
}