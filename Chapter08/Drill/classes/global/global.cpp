#include "global.h"
#include "date.h"
#include "year.h"
#include "day.h"
#include <termination>

void run()
{   
    std::cout.sync_with_stdio(false);
    try
    {
        date* today = allocate_date(date{year{2020}, month::feb, day{2}});
        date* tommorow = allocate_date(*today);
        tommorow->add_day(1);
        std::cout << *today << '\n' << *tommorow << std::endl;
        deallocate_date_all();
    }
    catch(date::invalid& e)
    {
        std::cout << e.what() << std::endl;
        deallocate_date_all();
    }
    termination_prompt();
}

date* allocate_date()
{
    void* raw = _aligned_malloc(sizeof(date), alignof(date));
    if(!raw) std::cout << "Failed to allocate memory";
    date* d = new(raw) date();
    ptr_table.push_back(d);
    return d;
}

date* allocate_date(const date& d)
{
    void* raw = _aligned_malloc(sizeof(date), alignof(date));
    if(!raw) std::cout << "Failed to allocate memory";
    return new(raw) date(d);
}

void deallocate_date(date*& ptr)
{
    if(ptr)
    {
        ptr->~date();
        _aligned_free(ptr);
        ptr = nullptr;
    }
}

void deallocate_date_all()
{
    if(ptr_table.empty())
    {
        std::cout << "Nothing to deallocate" << std::endl;
        return;
    }

    for(date*& ptr: ptr_table)
    {
        ptr->~date();
        _aligned_free(ptr);
        ptr = nullptr;
    }
    std::cout << "Everything was deallocated" << std::endl;
}