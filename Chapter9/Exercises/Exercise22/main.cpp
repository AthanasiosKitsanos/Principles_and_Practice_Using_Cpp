#include "calculator/calculator.h"

int main()
{
    roman_calculator calc{};
    calc.initialize_stream();
    calc.run();
}