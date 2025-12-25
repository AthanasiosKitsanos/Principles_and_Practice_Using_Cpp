#include "application.h"
#include <algorithm>
#include <iostream>
#include <termination>
#include <clear_screen>
#include "../includes/utilities/validate.h"

namespace console
{
    application::application()
    :m_cmd_map
    ({
        {"exit", utilities::command::exit},
        {"library", utilities::command::library},
        {"patrons", utilities::command::patrons},
        {"add", utilities::command::add},
        {"remove", utilities::command::remove},
        {"find", utilities::command::find},
        {"checkin", utilities::command::checkin},
        {"checkout", utilities::command::checkout},
        {"back", utilities::command::back},
        {"clear", utilities::command::clear},
        {"list", utilities::command::list},
        {"transactions", utilities::command::transact}
    }),
    m_bm(&m_tk, &m_cmd_map), m_pm(&m_tk, &m_cmd_map), m_tm(&m_cmd_map, &m_bm, &m_pm, &m_tk ), running(true) {}
    
    application::~application() {}
    
    void application::main_menu()
    {
        m_tk.reset();
        std::cout << "1. Manage Library(library) 2. Manage Patrons(patrons) 3. Transactions 4. Exit\n>>" << std::flush;
    }

    utilities::command application::await_command()
    {
        m_tk = std::move(m_is.get_command());
        if(m_tk.m_cmd.empty()) return utilities::command::unknown;
        std::unordered_map<std::string, utilities::command>::iterator it = m_cmd_map.find(m_tk.m_cmd);
        if(it != m_cmd_map.end()) return it->second;
        return utilities::command::unknown;
    }

    void application::execute_command(const utilities::command& cmd)
    {
        if(!m_tk.m_param.empty())
        {
            std::cout << "Unknown command\n" << std::flush;
            return;
        }
        switch(cmd)
        {
            case utilities::command::library:
                m_bm.run();
                break;
            case utilities::command::patrons:
                m_pm.run();
                break;
            case utilities::command::transact:
                m_tm.run();
                break;
            case utilities::command::exit:
                running = false;
                throw TerminationException{"Termination Requested"};
            case utilities::command::clear:
                clear_screen();
                break;
            default:
                std::cout << "Unknown command\n" << std::flush;
                break;
        }
    }

    void application::run()
    {
        try
        {
            do
            {
                main_menu();
                utilities::command cmd = await_command();
                execute_command(cmd);
            }while(running);
        }
        catch(TerminationException& e)
        {
            std::cout << e.what() << '\n' << std::flush;
        }
        termination_prompt();
    }

    void application::io_synchronization(const bool& is_sync)
    {
        if(!is_sync)
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
        }
    }

    void application::use_library()
    {
        m_bm.initialize();
    }

    void application::use_patron()
    {
        m_pm.initialize();
    }
}