#pragma once

#include <iostream>
#include <vector>
#include <termination>

#define key_word "quit"
#define _print_until "print_until"
#define _print_until_s "print_until_s"
#define _print_until_ss "print_until_ss"

void run(const std::vector<std::string>& vec);
void print_until(const std::vector<std::string>& vec, const std::string& quit);
void print_until_s(const std::vector<std::string>& vec, const std::string& quit);
void print_until_ss(const std::vector<std::string>& vec, const std::string& quit);
void generate_vector(std::vector<std::string>& vec);