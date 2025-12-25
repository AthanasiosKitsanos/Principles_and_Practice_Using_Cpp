#include "headers.h"
#include "stream.h"

Stream::Stream():count(0), number(0) {}
Stream::~Stream() {}

void Stream::get()
{
    char c;
    std::cin.get(c);

    switch(c)
    {
        case ' ':
            break;

        case '\n':
            break;

        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
            count++;
            int current_char = c - '0';

            if(number == 0)
            {
                number += current_char;
                break;
            }

            number = number * 10 + current_char;
            break;
        }
        
        default:
            count = 0;
            throw std::runtime_error("Invalid input");
    }
}

int Stream::digits()
{
    return count;
}

void Stream::print()
{
    std::cout << number << " is ";

    for(int i = count; i > 0; i--)
    {   
        switch(i)
        {
            case 4:
            {
                std::cout << number / 1000 << " thousands ";
                break;
            }
            case 3:
                std::cout << (number / 100) % 10 << " hunderds ";
                break;

            case 2:
                std::cout << (number / 10) % 10 << " tens ";
                break;

            case 1:
                std::cout << number % 10 << " ones" << std::endl;
                break;
        }    
    }
}

void Stream::reset_stream()
{
    count = 0;
    number = 0;
}