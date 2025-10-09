#include "global.h"
#include "random"

int main()
{
    std::vector<std::string> string_vector;
    generate_vector(string_vector);

    run(string_vector);

    return 0;
}