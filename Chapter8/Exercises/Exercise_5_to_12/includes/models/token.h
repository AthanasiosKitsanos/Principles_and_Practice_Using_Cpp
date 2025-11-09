#pragma once
#include <string>

namespace models
{
    class token
    {
        public:
            std::string m_cmd;
            std::string m_param;
        
            token();
            token(token&& other) noexcept;
            ~token();

            void reset();
            token& operator=(token&& other);
    };

    class cli_token
    {
        std::string input{50, '\n'};
        int input_index;
        char c;

        public:
    };
}