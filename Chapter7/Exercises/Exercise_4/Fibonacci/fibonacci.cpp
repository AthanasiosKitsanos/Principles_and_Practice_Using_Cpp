#include "fibonacci.h"
#include <iostream>

int fibonacci()
{
    int biggest = 1;
    int smallest = 0;
    int sum  = 0;

    while(true)
    {
        if(INT_MAX - biggest < smallest) break;

        sum = smallest + biggest;
        smallest = biggest;
        biggest = sum;
    }

    return biggest;
}