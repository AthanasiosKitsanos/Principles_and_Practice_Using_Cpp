#include "calculator.h"
#include "stream_pointer/stream_pointer.h"
#include "roman_int/roman_int.h"

roman_calculator::roman_calculator(): input(""), sp(nullptr), r_numeral(nullptr), repeat(1) {}

roman_calculator::~roman_calculator()
{
    if(sp)
    {
        sp->~stream_pointer();
        ::operator delete(sp);
        sp = nullptr;
    }
    free_r_numeral();
}

void roman_calculator::initialize_stream()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    void* raw = ::operator new(sizeof(stream_pointer));
    sp = new(raw) stream_pointer{};
}

void roman_calculator::free_r_numeral()
{
    if(r_numeral)
    {
        ::operator delete(r_numeral);
        r_numeral = nullptr;
    }
}

roman_int roman_calculator::expression()
{
    roman_int r{term()};
    while(isspace(*sp->start)) ++sp->start;
    switch(*sp->start)
    {
        case '+':
            ++sp->start;
            r += term();
            break;
        case '-':
            ++sp->start;
            r -= term();
            break;
    }
    return r;
}

roman_int roman_calculator::term()
{
    roman_int r{primary()};
    while(isspace(*sp->start)) ++sp->start;
    switch(*sp->start)
    {
        case '*':
            ++sp->start;
            r *= primary();
            return r;
        case '/':
            ++sp->start;
            {
                roman_int for_div{primary()};
                if(for_div.decimal > 0) r /= for_div;
                else
                {
                    r.is_valid = false;
                    std::cout << "Division by zero" << std::flush;
                }
            }
            return r;
        case '%':
            ++sp->start;
            {
                roman_int mod{primary()};
                if(mod.decimal > 0) r %= mod;
                else
                {
                    r.is_valid = false;
                    std::cout << "Modulo Division by zero" << std::flush;
                }
            }
            return r;
        default:
            return r;
    }
    return r;
}

roman_int roman_calculator::primary()
{
    roman_int r{};
    int next_num{0};
    while(isspace(*sp->start)) ++sp->start;
    switch(*sp->start)
    {
        case '(':
        {
            ++sp->start;
            roman_int r{expression()};
            while(isspace(*sp->start)) ++sp->start;
            if(*sp->start == ')') return r;
            r.is_valid = false;
            std::cout << "Forgot ')'\n" << std::flush;
            return r;
        }
        case 'I': case 'V': case 'X': case 'i': case 'v': case 'x':
        case 'L': case 'C': case 'D': case 'M': case 'l': case 'c': case 'd': case 'm':
                r.decimal = sp->return_decimal_value(*sp->start);
                ++sp->start;
                while(sp->is_valid_r_numeral(*sp->start))
                {
                    if(*sp->start == *(sp->start - 1))
                    {
                        ++repeat;
                        if(!sp->is_repeatable(*sp->start) || repeat > 3)
                        {
                            r.is_valid = false;
                            repeat = 1;
                            std::cout << "Roman numeral repeated more than it is allowed\n" << std::flush;
                            break;
                        }
                    }
                    next_num = sp->return_decimal_value(*sp->start);
                    if(r.decimal < next_num) r.decimal = next_num - r.decimal;
                    else r.decimal += next_num;
                    ++sp->start;
                }
                return r;
        default:
            r.is_valid = false;
            std::cout << "Invalid Entry\n" << std::flush;
            return r;
    }
    r.is_valid = false;
    std::cout << "No Entry\n" << std::flush;
    return r;
}

void roman_calculator::run()
{
    while(std::getline(std::cin, input))
    {
        if(input == "exit") break;
        sp->start = input.data();
        roman_int r{expression()};
        r_numeral = r.decimal_to_roman();
        std::cout << r_numeral << '\n' << r << '\n' << std::flush;
        free_r_numeral();
        input.clear();
    }
}