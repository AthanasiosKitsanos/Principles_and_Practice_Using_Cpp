#include "../../includes/utilities/validate.h"

namespace utilities
{
    void validate::has_parameter(const std::string& param)
    {
        if(param.length() == 0) throw std::invalid_argument{"command needs parameter"};
    }
}