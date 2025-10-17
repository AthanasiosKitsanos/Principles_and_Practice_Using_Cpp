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
        np.print();
        np.add_name();
        np.print();
        np.remove_name();
        np.print();
    }
    catch(TerminationException& e)
    {
        std::cout << e.what() << '\n';
    }
    termination_prompt();
}