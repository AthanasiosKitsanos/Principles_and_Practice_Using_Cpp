#pragma once

namespace console
{
    class application
    {
        bool is_running;
        
        public:
            application();
            ~application();
            void io_synchronization(const bool& ostream = true);

            void run();
            void init_library();
    };
}