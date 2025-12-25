#include "headers.h"
#include "combination.h"
#include "permutation.h"

int combination::combine(int value1, int value2)
{   
    int div = value2;

    for(int i = div - 1; i > 0; i--)
    {
        div *= i;
    }

    return permutation::permute(value1, value2) / div;
}