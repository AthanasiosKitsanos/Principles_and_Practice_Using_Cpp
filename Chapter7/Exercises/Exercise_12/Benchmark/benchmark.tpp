#include "benchmark.h"
#include <string>

template<typename Func>
double benchmark(Func f, const std::vector<std::string>& vec, const std::string& word)
{
    auto start = std::chrono::high_resolution_clock::now();
    f(vec, word);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
}