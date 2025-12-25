#pragma once
#include <string>

class name_pairs
{
    double age;
    std::string name;

    public:
        name_pairs();
        name_pairs(const std::string& name, const double& age);
        ~name_pairs();

        std::string get_name() const;
        double get_age() const;
        void set_name(const std::string& name);
        void set_age(const double& age);
        bool operator==(const name_pairs& other) const;
        bool operator!=(const name_pairs& other) const;
};