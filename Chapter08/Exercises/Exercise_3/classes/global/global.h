#pragma once
#include <ostream>
#include <termination>
#include "name_pairs.h"

inline void run()
{
    std::cout.sync_with_stdio(false);
    try
    {
        name_pairs np = name_pairs::initialize();
        std::cout << np << '\n';
        np.add_name();
        std::cout << np << '\n';
        np.remove_name();
        std::cout << np << '\n';
        name_pairs np1;
        np1.name = { "Thanos", "Anna"};
        np1.age = { 32, 31};
        name_pairs np2;
        np1.name = { "Thanos" };
        np1.age = { 32 };
        name_pairs np3;
        np3.name = { "Thanos", "Anna"};
        np3.age = { 32, 31};
        std::cout << "np1 == np2 " << (np1 == np2 ? "true\n" : "false\n");
        std::cout << "np1 != np2 " << (np1 != np2 ? "true\n" : "false\n");
        std::cout << "np1 == np3 " << (np1 == np3 ? "true\n" : "false\n");
        std::cout << "np1 != np3 " << (np1 != np3 ? "true\n" : "false\n");
    }
    catch(TerminationException& e)
    {
        std::cout << e.what() << '\n';
    }
    termination_prompt();
}