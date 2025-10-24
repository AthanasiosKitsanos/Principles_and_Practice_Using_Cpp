#include "application.h"
#include <memory>
#include <termination>
#include "book_manager.h"

namespace console
{
    application::application(): is_running(true) {}
    application::~application() {}

    //Disable sync check of std::ios to get less overhead. Need to use std::flush or std::endl for the output to appear
    //or it will appear before an std::cin 
    void application::io_synchronization(const bool& sync)
    {
        if(!sync)
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
        }
    }

    void application::wait_command() {} // TODO

    void application::execute() {} // TODO

    void application::run()
    {
        std::unique_ptr<library::book_manager> p_bm = std::make_unique<library::book_manager>();
        do
        {
            try
            {
                p_bm->menu();
            }
            catch(TerminationException& e)
            {
                is_running = false;
                std::cout << e.what();
            }   
        }while(is_running);
        termination_prompt();
    }
}