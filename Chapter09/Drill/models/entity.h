#pragma once
#include <string>

class entity
{
    public:
    std::string last_name;
    std::string name;
    std::string phone;
    std::string email;

    entity(const std::string& last_name, const std::string& name, const std::string& phone, const std::string& email);
    ~entity();
};