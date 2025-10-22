#include "application.h"
#include <termination>
#include "main_controller.h"

main_controller* application::operator->() { return mc_ptr; }
main_controller& application::operator*() { return *mc_ptr; }

application::application():mc_ptr(nullptr) {}
application::~application()
{
    if(mc_ptr)
    {
        mc_ptr->~main_controller();
        _aligned_free(mc_ptr);
        mc_ptr = nullptr;
    }
}
application::application(application&& other) noexcept :mc_ptr(other.mc_ptr)
{
    other.mc_ptr = nullptr;
}
application& application::operator=(application&& other) noexcept
{
    if(this != &other)
    {
        if(mc_ptr)
        {
            mc_ptr->~main_controller();
            _aligned_free(mc_ptr);
        }
        mc_ptr = other.mc_ptr;
        other.mc_ptr = nullptr;
    }
    return *this;
}

void application::initialize()
{
    initialize_main_controller();
}

void application::initialize_main_controller()
{
    void* raw = _aligned_malloc(sizeof(main_controller), alignof(main_controller));
    if(!raw)
    {
        std::cout << "Main Controller: ";
        throw std::bad_alloc{};
    }
    mc_ptr = new(raw) main_controller();
}