#include "../../includes/core/patron_manager.h"
#include <iostream>
#include <termination>
#include <clear_screen>
#include "../../includes/utilities/validate.h"
#include "../../includes/utilities/search.h"
#include "../../includes/models/token.h"

namespace core
{
    patron_manager::patron_manager(models::token* t, std::unordered_map<std::string, utilities::command>* cmd): m_tk(t), m_cmd_map(cmd), m_is() {}
    patron_manager::~patron_manager() {}

    void patron_manager::initialize()
    {
        m_patrons.reserve(2);
        m_patrons.emplace_back("Thanos", 1234, models::copyright_date{2024, 9, 12});
        m_patrons.emplace_back("Anna", 1325, models::copyright_date{2020, 5, 25});
        sort_patrons();
    }

    void patron_manager::sort_patrons()
    {
        for(int i = 1; i < m_patrons.size(); i++)
        {
            models::patron key = std::move(m_patrons[i]);
            int j{i};
            while(j > 0 && key.patron_name() < m_patrons[j - 1].patron_name())
            {
                m_patrons[j] = std::move(m_patrons[j - 1]);
                j--;
            }
            m_patrons[j] = std::move(key);
        }
    }

    bool patron_manager::id_exists(const short& id)
    {
        int left{0};
        int right = static_cast<int>(m_patrons.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(m_patrons[mid].patron_card_id() == id) return true;
            else if(m_patrons[mid].patron_card_id() < id) left = mid + 1;
            else right = mid;
        }
        return false;
    }

    models::patron* patron_manager::get_patron_address(const std::string& name)
    {
        int pos{utilities::search::get_position(m_patrons, name)};
        return &m_patrons[pos];
    }   

    bool patron_manager::patron_exists(const std::string& name) const
    {
        return utilities::search::get_position(m_patrons, name) != -1;
    }

    void patron_manager::find_patron()
    {
        int pos{utilities::search::get_position(m_patrons, m_tk->m_param)};
        if(pos == -1)
        {
            std::cout << "Patron not found\n";
            return;
        }
        std::cout << m_patrons[pos] << '\n';
    }

    void patron_manager::add_patron()
    {
        std::cout << "Enter Name: " << std::flush;
        std::string name{m_is.await_string()};
        std::cout << "Enter Card Id (4 digits): " << std::flush;
        short id{m_is.await_year()};
        if(id > 999 && id_exists(id))
        {
            std::cout << "Card Id already exists\n";
            return;
        }
        std::cout << "Enter Year: " << std::flush;
        short year{m_is.await_year()};
        std::cout << "Enter Month: " << std::flush;
        unsigned char month{m_is.await_m_or_d()};
        std::cout << "Enter Day: " << std::flush;
        unsigned char day{m_is.await_m_or_d()};
        int pos{utilities::search::get_lower_bound(m_patrons, name)};
        m_patrons.emplace(m_patrons.begin() + pos, name, id, models::copyright_date{year, month, day});
        std::cout << "Patron added\n";
    }

    void patron_manager::remove_patron()
    {
        int pos{utilities::search::get_position(m_patrons, m_tk->m_param)};
        if(pos == -1)
        {
            std::cout << "Patron not found\n";
            return;
        }
        m_patrons.erase(m_patrons.begin() + pos);
        std::cout << "Patron Removed\n";
    }

    void patron_manager::patron_menu()
    {
        m_tk->reset();
        std::cout << "1.List 2.Add 3.Remove 4.Find 5.Back 6.Exit\n>>" << std::flush;
    }

    utilities::command patron_manager::await_command()
    {
        *m_tk = std::move(m_is.get_command());
        std::unordered_map<std::string, utilities::command>::iterator it = m_cmd_map->find(m_tk->m_cmd);
        if(it != m_cmd_map->end()) return it->second;
        return utilities::command::unknown;
    }

    void patron_manager::execute_command(const utilities::command& cmd)
    {
        switch(cmd)
        {
            case utilities::command::exit:
                throw TerminationException{"Termination Requested"};
            case utilities::command::back:
                running = false;
                break;
            case utilities::command::list:
                clear_screen();
                std::cout << m_patrons << ">> Press any key to continue..." << std::flush;
                std::cin.get();
                break;
            case utilities::command::find:
                utilities::validate::has_parameter(m_tk->m_param);
                find_patron();
                break;
            case utilities::command::add:
                clear_screen();
                add_patron();
                break;
            case utilities::command::remove:
                utilities::validate::has_parameter(m_tk->m_param);
                remove_patron();
                break;
            case utilities::command::clear:
                clear_screen();
                break;
            default:
                std::cout << "Unkown command\n";
                break;
        }
    }

    void patron_manager::run()
    {
        running = true;
        do
        {
            try
            {
                patron_menu();
                utilities::command cmd = await_command();
                execute_command(cmd);
            }
            catch(models::copyright_date::invalid_date& e)
            {
                std::cout << e.what() << '\n';
            }
            catch(models::patron::invalid_id& e)
            {
                std::cout << e.what() << '\n';
            }
            catch(std::invalid_argument& e)
            {
                std::cout << e.what() << '\n';
            }
        }while(running);
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<models::patron>& vec)
{
    for(int i = 0; i < vec.size() - 1; ++i)
    {
        os << vec[i] << '\n';
    }
    os << vec[vec.size() - 1];
    return os;
}