#pragma once
#include <string>
#include <stdexcept>

namespace utilities
{
    class validate
    {
        public:
            static void has_parameter(const std::string& parameter);
    };
}