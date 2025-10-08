#include "global.h"
#include <iomanip>

vector_handler* initialize_vector_handler(const int& size)
{
    void* raw = _aligned_malloc(sizeof(vector_handler), alignof(vector_handler));
    if(!raw)
    {
        throw std::runtime_error("Failed to allocate memory");
    }

    std::cout << std::fixed << std::setprecision(2);
    return new(raw) vector_handler(size);
}

int get_size()
{
    while(true)
    {
        int size = 0;

        if(!(std::cin >> size))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if(!is_valid(size))
        {
            std::cout << "Size must be greater than zero: ";
            continue;
        }

        return size;
    }

    return -1;
}

bool is_valid(const int& size)
{
    if(size <= 0) return false;

    return true;
}

void free_memory(vector_handler*& ptr)
{
    if(ptr)
    {
        ptr->~vector_handler();
        _aligned_free(ptr);
        ptr = nullptr;
    }
}

void start()
{
    std::cout.sync_with_stdio(false);

    int size = 0;
    std::cout << "Enter the size of the vector: " << std::flush;

    size = get_size();

    vector_handler* vh_ptr = initialize_vector_handler(size);
    vh_ptr->print_vector();

    std::cout << "Max: " << vh_ptr->get_max() << std::endl;
    std::cout << "Min: " << vh_ptr->get_min() << std::endl;
    std::cout << "Median: " << vh_ptr->get_median() << std::endl;
    std::cout << "Mean: " << vh_ptr->get_mean() << std::endl;
    
    free_memory(vh_ptr);

    termination_prompt();
}