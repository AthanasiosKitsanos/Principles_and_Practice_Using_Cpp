#include "name_pairs.h"

name_pairs::name_pairs() {}
name_pairs::name_pairs(const std::string& n, const double& a):name(n), age(a) {}
name_pairs::~name_pairs() {}

std::string name_pairs::get_name() const { return name; }
double name_pairs::get_age() const { return age; }
void name_pairs::set_name(const std::string& name) { this->name = name; }
void name_pairs::set_age(const double& age) { this->age = age; }

bool name_pairs::operator==(const name_pairs& other) const
{
    return name == other.name && age == other.age;
}

bool name_pairs::operator!=(const name_pairs& other) const
{
    return name != other.name || age != other.age;
}