#include "calculator.h"
#include "stream_pointer/stream_pointer.h"
#include "roman_int/roman_int.h"

//Create a stream_pointer in the heap on object's construction
roman_calculator::roman_calculator(): input(""), sp(nullptr), r_numeral(nullptr)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    void* raw = ::operator new(sizeof(stream_pointer));
    sp = new(raw) stream_pointer{};
}

roman_calculator::~roman_calculator()
{
    if(sp) // Free the memory the stream_pointer occupies
    {
        sp->~stream_pointer();
        ::operator delete(sp);
        sp = nullptr;
    }
}

void roman_calculator::free_r_numeral() // Free the memory the r_numeral pointer occupies
{
    if(r_numeral)
    {
        ::operator delete(r_numeral);
        r_numeral = nullptr;
    }
}

//Calculates and return the result
roman_int roman_calculator::expression()
{
    roman_int r{term()}; // get a term result
    while(isspace(*sp->start)) ++sp->start; // skip space characters
    switch(*sp->start)
    {
        case '+':
            ++sp->start; // move the pointer to the next character
            r += term(); // add the next term
            return r;
        case '-':
            ++sp->start; // move the pointer to the next character
            r -= term(); // substract the next term
            return r;
        default:
            return r;
    }
}

//Calculates and returns the middle result and checks or sets the state of the object
roman_int roman_calculator::term()
{
    roman_int r{primary()}; // get a primary result
    if(!r.is_valid) return r;
    while(isspace(*sp->start)) ++sp->start; // skip space characters
    switch(*sp->start)
    {
        case '*':
            ++sp->start; // move the pointer to the next character
            r *= primary(); // multiply by the next primary
            return r;
        case '/':
            ++sp->start; // move the pointer to the next character
            {
                roman_int for_div{primary()};
                if(for_div.decimal > 0) r /= for_div; // if the denominator > 0, divide be the next primary
                else
                {
                    r.is_valid = false; // set to invalid state
                    std::cout << "Division by zero" << std::flush;
                }
            }
            return r;
        case '%':
            ++sp->start; // move the pointer to the next character
            {
                roman_int mod{primary()};
                if(mod.decimal > 0) r %= mod; // if the denominator > 0, get the modulo of the next primary
                else
                {
                    r.is_valid = false; // set to invalid state
                    std::cout << "Modulo Division by zero" << std::flush;
                }
            }
            return r;
        default:
            if(sp->is_valid_r_numeral(*sp->start))
            {
                r.is_valid = false;
                std::cout << "Roman Numerals without an operant" << std::endl;
            }
            return r;
    }
}

// Parses the input into int
roman_int roman_calculator::primary()
{
    while(isspace(*sp->start)) ++sp->start; // skip space characters
    switch(*sp->start)
    {
        case '(': // in case of '(' start a new expression and calculate it first
        {
            ++sp->start; // move the pointer to the next character
            roman_int r{expression()}; // get an expression
            while(isspace(*sp->start)) ++sp->start; // skip space characters
            if(*sp->start == ')') return r; // if the parentheses close return
            // else set object to invalid state
            r.is_valid = false; 
            std::cout << "Forgot ')'\n" << std::flush;
            return r;
        }
        case 'I': case 'V': case 'X': case 'i': case 'v': case 'x': // case of valid characters
        case 'L': case 'C': case 'D': case 'M': case 'l': case 'c': case 'd': case 'm':
        {
            // initialize helpers to reduce the dereferences
            short repeat{1}; // store how many times a roman character is repeated, all characters are repeated at least once
            int current_num{0}; // store the current number we will use in the for loop
            char prev_ch = toupper(*sp->start); // store the roman character to avoid multiple dereferences
            int sum{sp->return_decimal_value(prev_ch)}; // store the result of the roman numeral
            
            for(char current_ch = toupper(*(++sp->start)); sp->is_valid_r_numeral(current_ch); current_ch = toupper(*(++sp->start)))
            {
                if(prev_ch == current_ch) // if they are the same character
                {
                    ++repeat; // increment by 1
                    if(!sp->is_repeatable(current_ch)) //Check if the character can be repeated more than once. See stream_pointer.cpp
                    {
                        std::cout << "Roman numeral " << current_ch << " repeated more than once" << std::endl;
                        return roman_int{false};
                    }
                    if(repeat > 3) // Check if a repeatable character is repeated more than three times
                    {
                        std::cout << "Roman numeral " << current_ch << " can be repeated up to 3 times" << std::endl;
                        return roman_int{false};
                    }
                }
                else repeat = 1; // reset the repeater
                current_num = sp->return_decimal_value(current_ch); // store the value of the current roman character
                // Following the rule of substraction in roman numerals
                if(sum < current_num) sum = current_num - sum;
                else sum += current_num;
                prev_ch = current_ch; // store the current char to the previous one
            }
            return roman_int{sum};
        }
        default:
            std::cout << "Invalid Entry\n" << std::flush; // If the input is invalid
            return roman_int{false};
    }
    std::cout << "No Entry\n" << std::flush; // if there is no input
    return roman_int{false};
}

void roman_calculator::run()
{
    while(std::getline(std::cin, input))
    {
        if(input == "exit") break;
        sp->start = input.data(); // Initialize/Reset the stream_pointer to the start of the input string
        roman_int r{expression()}; // Get the result of an expression
        if(r.is_valid)
        {
            r_numeral = r.decimal_to_roman(); // get the equivalent roman numeral of the result
            std::cout << r_numeral << '\n' << r << '\n' << std::flush; // print the numeral and the decimal and see if the result is right
        }
        free_r_numeral(); // if r_numeral != nullptr free the memory block
        input.clear(); // reset the input
    }
}