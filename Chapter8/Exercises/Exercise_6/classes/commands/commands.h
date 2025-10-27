#pragma once
#include <string>
#include <termination>

namespace commands
{
    enum class type: unsigned char { unknown, add, remove, checkout, checkin, list, size, clear };

    type get_type(const std::string& command);
};