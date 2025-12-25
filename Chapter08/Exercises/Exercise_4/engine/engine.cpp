#include "engine.h"
#include <termination>
#include "main_controller.h"
#include <clear_screen>

engine::engine(): running(true)
{
    std::cout.sync_with_stdio(false);
}

engine::~engine() {}

void engine::start()
{
    try
    {
        app.initialize();
    }
    catch(std::bad_alloc& e)
    {
        running = false;
        std::cout << e.what() << '\n';
    }
    while(running)
    {
        try
        {
            app->prompt();
            app->wait_input();
            app->execute_command();
        }
        catch(TerminationException& e)
        {
            std::cout << e.what() << '\n';
            running = false;
        }
        catch(std::invalid_argument& e)
        {
            std::cout << e.what();
            std::cin.get();
            clear_screen();
        }
    }
    termination_prompt();
}