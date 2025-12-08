#include "year.h"
#include "parser_context/parser_context.h"
#include "global.h"

year::year(): months(12, not_a_month), y(0) {}
year::~year() {}

std::istream& operator>>(std::istream& is, year& y)
{
    std::string input{""};
    std::getline(is, input);
    if(input.empty())
    {
        std::cout << "Input is empty\n";
        return is;
    }
    global_pc = global::initialize_parser(input.data(), input.data() + input.size());
    while(global_pc->current < global_pc->end)
    {
        while(isspace(*global_pc->current)) ++global_pc->current;
        if(*global_pc->current != '{') 
        {
            std::cout << "Missed '{' character\n";
            global::free_parser(global_pc);
            return is;
        }
        ++global_pc->current;
        while(isspace(*global_pc->current)) ++global_pc->current;
        if(global_pc->current >= global_pc->end)
        if(!isalpha(*global_pc->current))
        {
            std::cout << "no letter after '{' character\n";
            global::free_parser(global_pc);
            return is;
        }
        {
            const char* word_start{global_pc->current};
            short word_end{0};
            while(isalpha(*global_pc->current))
            {
                ++global_pc->current;
                ++word_end;
            }
            std::string_view word(word_start, word_end);
            if(word != "year")
            {
                std::cout << "Misspelled word year\n";
                global::free_parser(global_pc);
                return is;
            }
        }
        while(isspace(*global_pc->current)) ++global_pc->current;
        auto result = std::from_chars(global_pc->current, global_pc->end, y.y);
        if(result.ec != std::errc{})
        {
            std::cout << "Failed to add year\n";
            is.clear(std::ios::failbit);
            global::free_parser(global_pc);
            return is;
        }
        global_pc->current = result.ptr;
        while(isspace(*global_pc->current)) ++global_pc->current;
        for(short i{0}; !is.fail() && i < y.months.size(); ++i)
        {
            if(*global_pc->current != '{') break;
            ++global_pc->current;
            is >> y.months[i];
            for(short j = i - 1; j >= 0; --j)
            {
                if(y.months[i].m == y.months[j].m)
                {
                    y.y = 0;
                    std::cout << "Duplicate month\n";
                    is.clear(std::ios::failbit);
                    global::free_parser(global_pc);
                    return is;
                }
            }
        }
        if(is.fail())
        {
            global::free_parser(global_pc);
            y.y = 0;
            return is;
        }
        if(*global_pc->current == '}')
        {
            global::free_parser(global_pc);
            return is;
        }
        std::cout << "Didn't close the with '}'\n";
        y.y = 0;
        is.clear(std::ios::failbit);
        global::free_parser(global_pc);
        return is;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const year& y)
{
    os << "{ year " << y.y << '\n';
    for(short i{0}; i < y.months.size() - 1; ++i) os << y.months[i];
    return os << "}";
}