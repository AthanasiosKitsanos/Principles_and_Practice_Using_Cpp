#include "commands.h"

namespace commands
{
    type get_type(const std::string& command)
    {
        if(command == "add") return type::add;
        if(command == "remove") return type::remove;
        if(command == "checkout") return type::checkout;
        if(command == "checkin") return type::checkin;
        if(command == "list") return type::list;
        if(command == "size") return type::size;
        if(command == "clear") return type::clear;
        return type::unknown;
    }
}