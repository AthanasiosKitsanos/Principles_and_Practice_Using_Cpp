#include <iostream>
#include <vector>
#include <termination>
#include "global.h"

int main()
{
    std::cout.sync_with_stdio(false);

    std::vector<int> vec(10);

    insert_values(vec);

    int max = maxv(vec);

    std::cout << "Max: " << max << std::endl;
    termination_prompt();
    return 0;
}