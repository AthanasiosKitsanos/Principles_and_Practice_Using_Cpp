#include "pch/pch.h"
#include "models/money.h"

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    {
        money m; // create an empty money instance
        std::cin >> m;
        std::cout << m << '\n';
        m.convert_to("DKK"); // convert to Danish Kroner
        std::cout << "m.convert_to('DKK') " << m << '\n';
        m.convert_to("USD"); // convert back to USD
        std::cout << "m.convert_to('USD') " << m << '\n';
        std::cout << "Currency == type\n";
        m.convert_to("USD"); // check if the type is the same
    }

    {
        money m2{"DKK", 1250};
        std::cout << "m2: " << m2 << '\n';

        std::cout << "Calling move contructor\n";
        money m3{std::move(m2)};
        std::cout << "m2 after move: " << m2 << '\n';
        std::cout << "m3: " << m3 << '\n';

        std::cout << "Move assignement\n";
        money m4 = std::move(m3);
        std::cout << "m3 after move: " << m3 << '\n';
        std::cout << "m4: " << m4 << '\n';
        
        std::cout << "Copy assignement\n";
        money m5 = m4;
        std::cout << "m5: " << m5 << '\n';
    }

    money m6{"USD", 1050};
    std::cout << "m6: " << m6 << '\n';
    m6 *= 2;
    std::cout << "m6 * 2: " << m6 << '\n';
    m6 /= 2;
    std::cout << "m6 / 2: " << m6 << '\n';

    money m7{"USD", 1000};
    std::cout << "m7: " << m7 << '\n';
    m7 += m6;
    std::cout << "m7 += m6: " << m7 << '\n';

    money m8 = m7 + m6;
    std::cout << "m8 = m7 + m6: " << m8 << '\n';

    money m9 = m7 - m6;
    std::cout << "m9 = m7 - m6: " << m9 << '\n';
}