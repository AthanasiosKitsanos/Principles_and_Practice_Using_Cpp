#include "application.h"
#include <memory>
#include <termination>
#include "book_manager.h"
#include <clear_screen>
#include <iostream>

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
    
    void init_library()
    {
        
    }

    void application::run()
    {
        std::unique_ptr<library::book_manager> p_bm = std::make_unique<library::book_manager>();
        do
        {
            try
            {
                p_bm->menu();
                p_bm->wait_command();
                p_bm->execute();
            }
            catch(TerminationException& e)
            {
                clear_screen();
                is_running = false;
                std::cout << e.what() << '\n';
            }
            catch(std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
            }
        }while(is_running);
        termination_prompt();
    }
}