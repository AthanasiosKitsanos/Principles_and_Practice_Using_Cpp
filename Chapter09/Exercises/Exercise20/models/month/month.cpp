#include "month.h"
#include "parser_context/parser_context.h"
#include "global.h"

month::month(const int mon): readings(31, not_a_reading), m(mon) {}
month::~month() {}

std::istream& operator>>(std::istream& is, month& m)
{
    while(isspace(*global_pc->current)) ++global_pc->current;
    if(!isalpha(*global_pc->current))
    {
        is.clear(std::ios::failbit);
        std::cout << "Month can not be empty\n";
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
        if(word != "month")
        {
            std::cout << "Need to add the word 'month'";
            is.clear(std::ios::failbit);
            return is;
        }
        while(isspace(*global_pc->current)) ++global_pc->current;
        word_start = global_pc->current;
        word_end = 0;
        while(isalpha(*global_pc->current))
        {
            ++global_pc->current;
            ++word_end;
        }
        word = std::string_view(word_start, word_end);
        for(short i{0}; i < m.months_names.size(); ++i)
        {
            if(m.months_names[i] == word)
            {
                m.m = i;
                break;
            }
        }
    }
    if(m.m == not_a_month)
    {
        is.clear(std::ios::failbit);
        std::cout << "Need to add the name of the month\n";
        return is;
    }
    while(isspace(*global_pc->current)) ++global_pc->current;
    for(short i{0}; !is.fail() && m.readings.size(); ++i)
    {
        if(*global_pc->current != '(') break;
        ++global_pc->current;
        is >> m.readings[i];
        for(short j = i - 1; j >= 0; --j)
        {
            if(m.readings[i].day == m.readings[j].day)
            {
                std::cout << "Duplicate Day\n";
                is.clear(std::ios::failbit);
                return is;
            }
        }
    }
    if(is.fail()) return is;
    if(*global_pc->current == '}')
    {
        ++global_pc->current;
        while(isspace(*global_pc->current)) ++global_pc->current;
        return is;
    }
    std::cout << "Month needs to close with '}'\n";
    is.clear(std::ios::failbit);
    return is;
}

std::ostream& operator<<(std::ostream& os, const month& m)
{
    if(m.m == not_a_month) return os;
    os << "\t{ month ";
    for(short m_i{0}; m_i < m.months_names.size(); ++m_i)
    {
        if(m.m == m_i)
        {
            os << m.months_names[m.m] << "\n\t\t";
            break;
        }
    }
    for(short j{0}; j < m.readings.size(); ++j) os << m.readings[j] << ' ';
    return os << "\n\t}\n";
}