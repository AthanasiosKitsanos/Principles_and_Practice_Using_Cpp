#pragma once

namespace utilities
{
    enum class command: short
    { 
        exit,
        transact,
        library,
        patrons,
        unknown,
        add,
        remove,
        list,
        checkin,
        checkout,
        back,
        clear,
        find
    };
}