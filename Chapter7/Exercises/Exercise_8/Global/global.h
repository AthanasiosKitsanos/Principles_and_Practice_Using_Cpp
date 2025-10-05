#pragma once
#include "g_headers.h"

void run();

void fill_names_vector(std::vector<std::string>& names);
void fill_age_vector(std::vector<double>& age, const std::vector<std::string>& names);
bool is_valid_age(const double& age);
double get_age();
void print_elements(const std::vector<std::string>& names, const std::vector<double>& age);
std::vector<std::string> sort_names_vector(std::vector<std::string> names);
std::vector<double> order_age_by_name(const std::vector<std::string>& string_vector, const std::vector<std::string>& sorted_string_vector, const std::vector<double>& age);