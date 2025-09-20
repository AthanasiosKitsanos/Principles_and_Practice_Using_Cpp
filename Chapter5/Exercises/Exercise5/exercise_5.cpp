#include "headers.h"
#include "global.h"
#include "token.h"
#include "token_stream.h"

int main()
{
    bool play = true;

    init_global_pointer();

    while(play)
    {
        try
        {
            int val = 0;

            while(std::cin)
            {
                Token token = global_ts->get();

                if(token.kind == ';')
                {
                    std::cout << "= " << val << std::endl;
                    continue;
                }
                else if(token.kind == 'q')
                {
                    play = false;
                    break;
                }

                global_ts->putback(token);

                val = token.binary_or();
            }
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    delete_global_pointer();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit..." << std::endl;
    std::cin.get();

    return 0;
}