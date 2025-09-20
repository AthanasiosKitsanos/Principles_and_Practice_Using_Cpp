#include "headers.h"
#include "input_stream.h"
#include "token.h"

token input_stream::get_input()
{
    char c;
    std::cin >> c;

    switch(c)
    {
        case 'q': case 'Q': case 'p': case 'P': case 'c': case 'C':
            return token{c};

        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
            return token{'8', c -'0'};
        }

        default:
            throw std::runtime_error("Invalid input");
    }
}