#include "headers.h"
#include "token.h"
#include "token_stream.h"

int main()
{
    try
    {
        initialize_stream_pointer();

        double val = 0;
        
        while(std::cin)
        {
            Token t = ts_global->get();

            if(t.kind == ';')
            {
                std::cout << "= " << val << std::endl;
                continue;
            }
            else if(t.kind == 'q')
            {
                break;
            }

            ts_global->putback(t);
            val = t.expression();
        }
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
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