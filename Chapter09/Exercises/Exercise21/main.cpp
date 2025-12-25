#include "roman_int.h"

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    roman_int numeral{};
    std::cin >> numeral;
    std::cout << "Roman " << numeral << " equals " << numeral.as_int() << '\n';
}