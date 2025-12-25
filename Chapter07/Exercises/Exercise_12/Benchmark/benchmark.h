#pragma once

#include <vector>
#include <thread>
#include <chrono>

template<typename Func>
double benchmark(Func f, const std::vector<std::string>& vec, const std::string& word);

#include "benchmark.tpp"