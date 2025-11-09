#pragma once

namespace console
{
    class application;

    class smart_ptr
    {
        application* app;
        
        public:
            smart_ptr();
            ~smart_ptr();

            smart_ptr(const smart_ptr& other) = delete;
            smart_ptr& operator=(const smart_ptr& other) = delete;

            smart_ptr(smart_ptr&& other) noexcept;
            smart_ptr& operator=(smart_ptr&& other) noexcept;
            
            void initialize();

            application* operator->();
            application& operator*();
    };
}