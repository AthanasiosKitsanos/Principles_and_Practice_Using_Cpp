#include "conversion.h"
#include "vec_token.h"
#include <chrono>

template<typename Ret, typename... Args>
void vector_conversion::run_loop_for(Ret (vector_conversion::*func) (Args...))
{
    char c;
    do
    {
        system("cls");
        auto start = std::chrono::high_resolution_clock::now();
        (this->*func)();
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Time taken for execution: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0 << std::endl;
        std::cout << "Press any key to run again or 'c' to continue... ";
    }
    while(std::cin.get(c) && c != 'c');

    std::cin.get();
}