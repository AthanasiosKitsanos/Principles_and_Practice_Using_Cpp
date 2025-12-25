#pragma once
#include "helper.h"
#include <ostream>
#include <termination>

struct name_pairs
{
    std::vector<std::string> name;
    std::vector<double> age;
    void read_names(const bool& loop);
    void read_ages(const bool& loop);
    void sort_vectors();
    void add_name();
    void remove_name();
    void sort_new_addition();
    static name_pairs initialize();
    bool operator==(const name_pairs& other)
    {
        return name == other.name && age == other.age;
    }
    bool operator!=(const name_pairs& other)
    {
        return name != other.name && age != other.age;
    }
};

std::ostream& operator<<(std::ostream& os, const name_pairs& np);
