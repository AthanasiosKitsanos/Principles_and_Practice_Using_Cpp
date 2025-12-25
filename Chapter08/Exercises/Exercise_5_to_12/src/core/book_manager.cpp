#include "../../includes/core/book_manager.h"
#include <clear_screen>
#include <iostream>
#include <termination>
#include "../../includes/utilities/validate.h"
#include "../../includes/utilities/search.h"
#include "../../includes/models/token.h"

namespace core
{
    book_manager::book_manager(models::token* t, std::unordered_map<std::string, utilities::command>* cmd_map): m_tk(t), m_cmd_map(cmd_map), m_is() {}
    book_manager::~book_manager() {}

    void book_manager::initialize()
    {
        m_lib.reserve(5);
        m_lib.emplace_back("The Silent Observer", "Elena Marlowe", "123A", models::copyright_date{2018, 5, 12}, models::genre::fiction);
        m_lib.emplace_back("Shadows of Glass", "Marcus Trent", "847B", models::copyright_date{2019, 11, 3}, models::genre::periodical);
        m_lib.emplace_back("The Quantum Thief", "Hannu Rajaniemi", "314R", models::copyright_date{2011, 2, 20}, models::genre::fiction);
        m_lib.emplace_back("Dust and Code", "Nina Karras", "762K", models::copyright_date{2021, 7, 14}, models::genre::biography);
        m_lib.emplace_back("Axioms of Power", "Tobias Reinhardt", "901T", models::copyright_date{2021, 7, 14}, models::genre::children);
        sort_lib();
    }

    void book_manager::sort_lib()
    {
        for(int i = 1; i < m_lib.size(); i++)
        {
            models::books key = std::move(m_lib[i]);
            int j = i;
            while(j > 0 && key.get_title() < m_lib[j - 1].get_title())
            {
                m_lib[j] = std::move(m_lib[j - 1]);
                j--;
            }
            m_lib[j] = std::move(key);
        }
    }

    bool book_manager::isbn_exists(const std::string& isbn)
    {
        int left{0};
        int right = static_cast<int>(m_lib.size());
        int mid{0};
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(m_lib[mid].get_isbn() == isbn) return true;
            else if(m_lib[mid].get_isbn() < isbn) left = mid + 1;
            else right = mid;
        }
        return false;
    }

    void book_manager::find_book()
    {
        int pos{utilities::search::get_position(m_lib, m_tk->m_param)};
        if(pos == -1)
        {
            std::cout << "Book not found\n";
            return;
        }
        std::cout << m_lib[pos] << '\n';
    }

    models::books* book_manager::get_book_address(const std::string& title)
    {
        int pos{utilities::search::get_position(m_lib, title)};
        return &m_lib[pos];
    }

    bool book_manager::book_exists(const std::string& title) const
    {
        return utilities::search::get_position(m_lib, title) != -1;
    }

    void book_manager::add_book()
    {
        std::cout << "Enter Title: " << std::flush;
        std::string title{m_is.await_string()};
        std::cout << "Enter Auhtor: " << std::flush;
        std::string author{m_is.await_string()};
        std::cout << "Enter ISBN: " << std::flush;
        std::string isbn{m_is.await_string()};
        if(isbn_exists(isbn))
        {
            std::cout << "ISBN already exists" << std::flush;
            return;
        }
        std::cout << "Enter Year: " << std::flush;
        short year{m_is.await_year()};
        std::cout << "Enter Month: " << std::flush;
        unsigned char month{m_is.await_m_or_d()};
        std::cout << "Enter Day: " << std::flush;
        unsigned char day{m_is.await_m_or_d()};
        std::cout << "Enter genre: " << std::flush;
        models::genre gen{m_is.await_genre()};
        int pos{utilities::search::get_lower_bound(m_lib, title)};
        m_lib.emplace(m_lib.begin() + pos, title, author, isbn, models::copyright_date{year, month, day}, gen);
        std::cout << "Book added successfully\n";
    }

    void book_manager::remove_book()
    {
        int pos{utilities::search::get_position(m_lib, m_tk->m_param)};
        if(pos == -1)
        {
            std::cout << "Book not found\n";
            return;
        }
        m_lib.erase(m_lib.begin() + pos);
        std::cout << "Book removed successfilly\n";
    }

    void book_manager::library_menu()
    {
        m_tk->reset();
        std::cout << "1.List 2.Add 3.Remove 4.Checkout 5.Checkin 6.Back 7.Exit\n>>" << std::flush; 
    }

    utilities::command book_manager::await_command()
    {
        *m_tk = std::move(m_is.get_command());
        std::unordered_map<std::string, utilities::command>::iterator it = m_cmd_map->find(m_tk->m_cmd);
        if(it != m_cmd_map->end()) return it->second;
        return utilities::command::unknown;
    }

    void book_manager::execute_command(const utilities::command& cmd)
    {
        switch(cmd)
        {
            case utilities::command::exit:
                throw TerminationException{"Termination Requested"};
            case utilities::command::back:
                running = false;
                clear_screen();
                break;
            case utilities::command::list:
                clear_screen();
                std::cout << m_lib << ">> Press any key to continue..." << std::flush;
                std::cin.get();
                break;
            case utilities::command::find:
                utilities::validate::has_parameter(m_tk->m_param);
                clear_screen();
                find_book();
                break;
            case utilities::command::add:
                clear_screen();
                add_book();
                break;
            case utilities::command::remove:
                utilities::validate::has_parameter(m_tk->m_param);
                remove_book();
                break;
            case utilities::command::clear:
                clear_screen();
                break;
            default:
                std::cout << "Unknown Command\n";
                break;
        }
    }

    void book_manager::run()
    {
        running = true;
        do
        {
            try
            {
                library_menu();
                utilities::command cmd = await_command();
                execute_command(cmd);
            }
            catch(models::books::invalid_isbn& e)
            {
                std::cout << e.what() << "\n";
            }
            catch(models::copyright_date::invalid_date& e)
            {
                std::cout << e.what() << "\n";
            }
            catch(std::invalid_argument& e)
            {
                std::cout << e.what() << "\n";
            }
        }while(running);
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<models::books>& vec)
{
    for(int i = 0; i < vec.size() - 1; i++)
    {
        os << vec[i] << '\n';
    }
    os << vec[vec.size() - 1];
    return os;
}