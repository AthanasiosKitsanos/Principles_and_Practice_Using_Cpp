#include "headers.h"
#include "stream.h"

int main()
{   
    Stream str;

    try
    {   
        while(std::cin)
        {
            char c;
            std::cin.get(c);

            if(c == 'q')
            {
                str.get();
                break;
            }

            if(c == '\n')
            {
                if(str.digits() == 0)
                {
                    std::cout << "No input found" << std::endl;
                    continue;
                }
                
                str.print();
                str.reset_stream();
            }

            std::cin.putback(c);
            str.get();
        }
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}