#include "../../includes/console/smart_ptr.h"
#include "../../application/application.h"
#include <iostream>

namespace console
{
    smart_ptr::smart_ptr(): app(nullptr) {}
    smart_ptr::~smart_ptr()
    {
        if(app)
        {
            app->~application();
            _aligned_free(app);
            app = nullptr;
        }
    }

    smart_ptr::smart_ptr(smart_ptr&& other) noexcept : app(other.app)
    {
        other.app = nullptr;
    }

    smart_ptr& smart_ptr::operator=(smart_ptr&& other) noexcept
    {
        if(this != &other)
        {
            if(app)
            {
                app->~application();
                _aligned_free(app);
            }
            app = other.app;
            other.app = nullptr;
        }
        return *this;
    }

    void smart_ptr::initialize()
    {
        void* raw = _aligned_malloc(sizeof(application), alignof(application));
        if(!raw)
        {
            std::cout << "Failed to allicate memory for application: ";
            throw std::bad_alloc();
        }
        app = new(raw) application();
    }

    application* smart_ptr::operator->() { return app; }
    application& smart_ptr::operator*() { return *app; }
}