#include "headers.h"
#include "permutation.h"

int permutation::permute(int value1, int& value2)
{
    int sub = value1 - value2;

    for(int i = value1 - 1; i > 0; i--)
    {
        value1 *= i;
    }

    for(int i = sub - 1; i > 0; i--)
    {
        sub *= i;
    }

    return value1 / sub;
}