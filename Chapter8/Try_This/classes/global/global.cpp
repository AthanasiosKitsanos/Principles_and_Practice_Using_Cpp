#include "global.h"
#include "date.h"
#include "year.h"
#include <termination>

void run()
{
    std::cout.sync_with_stdio(false);
    try
    {
        void* raw = _aligned_malloc(sizeof(date), alignof(date));
        if(!raw)
        {
            throw date::invalid{"Failed to allocate the date object"};
        }
        date* d1 = new(raw) date{year{2025},month::jan,15}; //test the initiallization
        std::cout << *d1 << std::endl;
        d1->~date();
        d1 = nullptr;

        month m{month::jan}; // testing the operation << overload
        std::cout << m << std::endl;
        ++m;
        std::cout << m << std::endl;

        date* d2 = new(raw) date(); // testing the default constractor
        std::cout << *d2 << std::endl;
        d2->~date();

        _aligned_free(d2);
        d2 = nullptr;
        raw = nullptr;
    }
    catch(date::invalid& e)
    {
        std::cout << e.what() << std::endl;
    }
    termination_prompt();
}