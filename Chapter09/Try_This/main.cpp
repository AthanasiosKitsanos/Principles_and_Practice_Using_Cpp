#include <iostream>
#include <format>

//#define IGNORE

int main()
{
    constexpr double d = 1234.56789 ;
    #ifdef IGNORE
        int birth_year{1993};
        std::cout << "Decimal\tHexadecimal\tOctal\n";
        std::cout << birth_year << '\t' << std::hex << birth_year << '\t' << std::oct << birth_year << std::endl; 
    #endif

    #ifndef IGNORE
        std::cout << std::format("-{:12} - {:12.8f} - {:30.20e} -\n", d, d, d);
    #endif
}