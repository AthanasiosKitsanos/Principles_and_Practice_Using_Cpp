#include "../../includes/models/token.h"

namespace models
{
    token::token(): m_cmd(""), m_param("") {}
    token::~token() {}

    token::token(token&& other) noexcept : m_cmd(std::move(other.m_cmd)), m_param(std::move(other.m_param)) {}

    void token::reset()
    {
        m_cmd.clear();
        m_param.clear();
    }

    token& token::operator=(token&& other)
    {
        if(this != &other)
        {
            m_cmd = std::move(other.m_cmd);
            m_param = std::move(other.m_param);
        }
        return *this;
    }
}