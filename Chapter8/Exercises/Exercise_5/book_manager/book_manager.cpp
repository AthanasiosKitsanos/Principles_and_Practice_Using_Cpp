#include "book_manager.h"
#include <iostream>
#include <clear_screen>
#include <algorithm>

namespace library
{
    book_manager::book_manager(): c('\0')
    {
        m_book_lib.reserve(5);
        m_book_lib.emplace_back("The Silent Observer", "Elena Marlowe", "123A", copyright_date{2018, 5, 12});
        m_book_lib.emplace_back("Shadows of Glass", "Marcus Trent", "847B", copyright_date{2019, 11, 3});
        m_book_lib.emplace_back("The Quantum Thief", "Hannu Rajaniemi", "314R", copyright_date{2011, 2, 20});
        m_book_lib.emplace_back("Dust and Code", "Nina Karras", "762K", copyright_date{2021, 7, 14});
        m_book_lib.emplace_back("Axioms of Power", "Tobias Reinhardt", "901T", copyright_date{2021, 7, 14});
        vec_sort(m_book_lib);
    }

    book_manager::~book_manager() {}

    void book_manager::print_sizes()
    {
        std::cout << "m_cmd size: " << sizeof(commands::type) << '\n'
        << "Short: " << sizeof(short) << '\n'
        << "Unsigned Char: " << sizeof(unsigned char) << '\n'
        << "copyright date: " << sizeof(copyright_date) << '\n'
        << "String Size: " << sizeof(std::string) << '\n'
        << "Book size: " << sizeof(book) << '\n'
        << "Input Stream: " << sizeof(i_stream) << '\n'
        << "Book Manager: " << sizeof(book_manager) << std::endl;
    }

    void book_manager::vec_sort(std::vector<library::book>& vec)
    {
        for(int i = 1; i < vec.size(); i++)
        {
            library::book key = std::move(vec[i]);
            int j = i;
            while(j > 0 && key.get_title() < vec[j - 1].get_title())
            {
                vec[j] = std::move(vec[j - 1]);
                j--;
            }
            vec[j] = std::move(key);
        }
    }

    int book_manager::vec_lower_bound(const std::string& title)
    {
        int left{0};
        int right = m_book_lib.size();
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(m_book_lib[mid].get_title() < title) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int book_manager::vec_find_title(const std::string& title)
    {
        int left{0};
        int right = m_book_lib.size();
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(m_book_lib[mid].get_title() == title) return mid;
            else if(m_book_lib[mid].get_title() < title) left = mid + 1;
            else if(m_book_lib[mid].get_title() > title) right = mid;
        }
        return -1;
    }

    void book_manager::menu()
    {
        std::cout << "1. Add New\n2. Delete\n3. Checkout\n4. Checkin\n5. List (Check Availability)\n6. Close\n>> " << std::flush;
    }

    void book_manager::wait_command()
    {
        std::string command = m_is.get_input(c);
        m_cmd = commands::get_type(command);
    }

    void book_manager::execute()
    {
        switch(m_cmd)
        {
            case commands::type::add:
                try
                {
                    add_new_book();
                    std::cout << "Book added succesfully " << std::flush;
                }
                catch(book::invalid_isbn& e)
                {
                    std::cout << e.what() << ' ' << std::flush;
                }
                catch(copyright_date::invalid& e)
                {
                    std::cin.clear();
                    std::cout << e.what() << ' ' << std::flush;
                }
                std::cin.get();
                break;
            case commands::type::remove:
                remove_book();
                std::cin.get();
                break;
            case commands::type::checkout:
                check_out_book();
                std::cin.get();
                break;
            case commands::type::checkin:
                check_in_book();
                std::cin.get();
                break;
            case commands::type::list:
                std::cout << m_book_lib << std::flush;
                std::cin.get();
                break;
            case commands::type::size:
                print_sizes();
                std::cin.get();
                break;
            case commands::type::clear:
                clear_screen();
                break;
            default:
                std::cout << "Unknown Command\n" << std::flush;
                std::cin.get();
                break;
        }
    }

    void book_manager::add_new_book()
    {
        std::cout << "Enter title: " << std::flush;
        std::string title{m_is.get_input(c)};
        std::cout << "Enter author: " << std::flush;
        std::string author{m_is.get_input(c)};
        std::cout << "Enter isbn: " << std::flush;
        std::string isbn{m_is.get_input(c)};
        std::cout << "Enter year: " << std::flush;
        short year{m_is.get_short(c)};
        std::cout << "Enter month: " << std::flush;
        unsigned char month{m_is.get_usinged_char(c)};
        std::cout << "Enter day: " << std::flush;
        unsigned char day{m_is.get_usinged_char(c)};
        int pos{vec_lower_bound(title)};
        m_book_lib.emplace(m_book_lib.begin() + pos, title, author, isbn, copyright_date{year, month, day});
    }

    void book_manager::remove_book()
    {
        std::cout << "Enter title to remove: " << std::flush;
        std::string title{m_is.get_input(c)};
        int pos = vec_find_title(title);
        if(pos == -1)
        {
            std::cout << "Title not found" << std::flush;
            return;
        }
        m_book_lib.erase(m_book_lib.begin() + pos);
        std::cout << "Book removed successfully " << std::flush;
    }

    void book_manager::check_out_book()
    {
        std::string title = m_is.get_input(c);
        int pos = vec_find_title(title);
        if(pos == -1)
        {
            std::cout << "Book not found" << std::flush;
            return;
        }
        m_book_lib[pos].check_out();
        std::cout << m_book_lib[pos].get_title() << " checked out" << std::flush;
    }

    void book_manager::check_in_book()
    {
        std::string title = m_is.get_input(c);
        int pos = vec_find_title(title);
        if(pos == -1)
        {
            std::cout << "Book not found" << std::flush;
            return;
        }
        m_book_lib[pos].check_in();
        std::cout << m_book_lib[pos].get_title() << " checked in" << std::flush;
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<library::book>& bl)
{
    for(int i = 0; i < bl.size() - 1; i++)
    {   
        os << bl[i] << '\n';
    }
    os << bl[bl.size() - 1];
    return os;
}