#include "headers.h"
#include "flow_handler.h"
#include "validation.h"
#include "operation_handler.h"

flow_handler::flow_handler():exit(false) {}

flow_handler::~flow_handler() {}

flow_handler* flow_handler::initialize_handler()
{
    void* rawMemory = _aligned_malloc(sizeof(flow_handler), alignof(flow_handler));
    if(!rawMemory)
    {
        std::cerr << "Allocation failed" << std::endl;
        return nullptr;
    }

    return new(rawMemory) flow_handler();
}

void flow_handler::free_flow_handler(flow_handler*& ptr)
{
    ptr->~flow_handler();
    _aligned_free(ptr);
    ptr = nullptr;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();
}

void flow_handler::get_numbers()
{
    while(true)
    {
        int counter = 0;
        
        while(counter < 2)
        {
            t = input_stream::get_input();

            if(t.kind == 'q' || t.kind == 'Q')
            {
                exit = true;
                return;
            }

            switch(counter)
            {
                case 0:
                    value1 = t.value;
                    break;
                
                case 1:
                    value2 = t.value;
                    break;
            }

            counter++;
        }

        if(!validation::validate(value1, value2))
        {
            continue;;
        }

        break;
    }
}

void flow_handler::get_operation()
{   
    std::cout << "\nSelect operation to execute" << std::endl;
    std::cout << "Permutation (p)" << std::endl;
    std::cout << "Combination (c)" << std::endl;
    std::cout << "Quit (q)" << std::endl;

    while(true)
    {
        t = input_stream::get_input();

        if(t.kind == 'q' || t.kind == 'Q')
        {
            exit = true;
            return;
        }

        if(!validation::valid_operation(t.kind))
        {
            continue;
        }

        break;
    }
}

void flow_handler::execute_operation()
{
    operation_handler op = operation_handler{t.kind, value1, value2};

    result = op.execute_operation();

    switch(t.kind)
    {
        case 'p': case 'P':
            std::cout << "\nPermutation Result: " << result << std::endl;
            break;

        case 'c': case 'C':
            std::cout << "Combination Result: " << result << std::endl;
            break;
    }

    std::cout << std::endl;
}

void flow_handler::run()
{   
    while(true)
    {
        try
        {
            std::cout << "Enter 2 integer numbers" << std::endl;

            get_numbers();

            if(exit)
            {
                break;
            }

            get_operation();

            if(exit)
            {
                break;
            }

            execute_operation();
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}