#include "../../includes/core/transaction_manager.h"
#include <iostream>
#include <termination>
#include <clear_screen>
#include "../../includes/core/book_manager.h"
#include "../../includes/core/patron_manager.h"
#include "../../includes/utilities/search.h"

namespace core
{
    transaction_manager::transaction_manager(std::unordered_map<std::string, utilities::command>* cmd, book_manager* bm, patron_manager* pm, models::token* tk): m_cmd_map(cmd), m_bm(bm), m_pm{pm}, m_tk(tk) {}
    transaction_manager::~transaction_manager() {}

    const std::vector<models::transaction>& transaction_manager::get_transactions_history() const { return m_transactions; }

    void transaction_manager::check_out_book()
    {
        if(!m_bm->book_exists(m_tk->m_param))
        {
            std::cout << "Book not found\n";
            return;
        }
        models::books* book_ptr = m_bm->get_book_address(m_tk->m_param);
        if(!book_ptr->availability())
        {
            std::cout << "Book is not available\n";
            return;
        }
        m_tk->reset();
        std::cout << "Enter a name: " << std::flush;
        m_tk->m_param = std::move(m_is.await_string());
        if(!m_pm->patron_exists(m_tk->m_param))
        {
            std::cout << "Patron does not exist\n";
            return;
        }
        models::patron* patron_ptr = m_pm->get_patron_address(m_tk->m_param);
        book_ptr->check_out();
        std::cout << "Enter today's year: " << std::flush;
        short year{m_is.await_year()};
        std::cout << "Enter today's month: " << std::flush;
        unsigned char month{m_is.await_m_or_d()};
        std::cout << "Enter today's day: " << std::flush;
        unsigned char day{m_is.await_m_or_d()};
        int pos{utilities::search::get_position(m_transactions, m_tk->m_param)};
        if(pos == -1)
        {
            int patron_pos{utilities::search::get_lower_bound(m_transactions, m_tk->m_param)};
            m_transactions.emplace(m_transactions.begin() + patron_pos, patron_ptr, book_ptr, models::copyright_date{year, month, day});
        }
        else
        {
            int book_pos{utilities::search::get_lower_bound(m_transactions[pos].get_books(), book_ptr->get_title())};
            m_transactions[pos].get_books().emplace(m_transactions[pos].get_books().begin() + book_pos, book_ptr, models::copyright_date{year, day, month});
        }
        patron_ptr->set_fee(patron_ptr->patron_fees() + 2);
        std::cout << "Book renter successfully\n";
    }

    void transaction_manager::check_in_book()
    {
        int pos{utilities::search::get_position(m_transactions, m_tk->m_param)};
        if(pos == -1)
        {
            std::cout << "No such name found\n";
            return;
        }
        m_tk->reset();
        std::cout << "Enter the title of the book\n" << std::flush;
        m_tk->m_param = std::move(m_is.await_string());
        int book_pos{utilities::search::get_position(m_transactions[pos].get_books(), m_tk->m_param)};
        if(book_pos == -1)
        {
            std::cout << "No book found\n";
            return;
        }
        m_transactions[pos]->set_fee(m_transactions[pos]->patron_fees() -2);
        m_transactions[pos].get_books()[book_pos].m_book_ptr->check_in();
        m_transactions[pos].get_books().erase(m_transactions[pos].get_books().begin() + book_pos);
        if(!m_transactions[pos].get_books().empty()) 
        {
            m_transactions.erase(m_transactions.begin() + pos);   
        }
        std::cout << "Book checkedin\n";
    }

    void transaction_manager::find_patron_with_fee() const
    {
        int pos{utilities::search::get_position(m_transactions, m_tk->m_param)};
        if(pos == -1)
        {
            std::cout << "Patron not found\n";
            return;
        }
        std::cout << m_transactions[pos] << '\n';
    }

    void transaction_manager::transaction_menu()
    {
        m_tk->reset();
        std::cout << "1. Get 'Name' 2. Checkin 3. Checkout 4. Back 5. Exit\n" << std::flush;
    }

    utilities::command transaction_manager::await_command()
    {
        *m_tk= std::move(m_is.get_command());
        std::unordered_map<std::string, utilities::command>::iterator it = m_cmd_map->find(m_tk->m_cmd);
        if(it != m_cmd_map->end()) return it->second;
        return utilities::command::unknown;
    }

    void transaction_manager::execute_command(const utilities::command& cmd)
    {
        switch(cmd)
        {
            case utilities::command::list:
                std::cout << get_transactions_history() << std::flush;
                std::cin.get();
                break;
            case utilities::command::back:
                running = false;
                break;
            case utilities::command::exit:
                throw TerminationException{"Termination Reqeusted"};
            case utilities::command::clear:
                clear_screen();
                break;
            case utilities::command::checkout:
                check_out_book();
                break;
            case utilities::command::checkin:
                check_in_book();
                break;
            case utilities::command::find:
                find_patron_with_fee();
                break;
            default:
                std::cout << "Unknown Command\n" << std::flush;
                break;
        }
    }

    void transaction_manager::run()
    {
        running = true;
        do
        {
            try
            {
                transaction_menu();
                utilities::command cmd = await_command();
                execute_command(cmd);
            }
            catch(models::copyright_date::invalid_date& e)
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

std::ostream& operator<<(std::ostream& os, const std::vector<models::transaction>& transactions)
{
    for(const models::transaction& t: transactions)
    {
        os << t.print_books();
    }
    return os;
}