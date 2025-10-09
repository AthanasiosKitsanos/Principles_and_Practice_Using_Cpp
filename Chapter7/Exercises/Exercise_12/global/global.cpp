#include "global.h"
#include "benchmark.h"
#include <iomanip>
#include <random>
#include <algorithm>

void generate_vector(std::vector<std::string>& vec)
{
    int size = 100000;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist (0, size - 1);
    vec.resize(size, "hello");
    vec[dist(gen)] = key_word;
    vec[dist(gen)] = key_word;
}

void run(const std::vector<std::string>& vec)
{
    char c;
    std::cout.sync_with_stdio(false);
    std::vector<std::string> sorted = vec;
    std::sort(sorted.begin(), sorted.end());
    do
    {
        system("cls");
        std::cout << std::fixed << std::setprecision(3);
        double pu_time = benchmark(print_until, vec, key_word); // this checks in the original vector
        double pus_time = benchmark(print_until_s, sorted, key_word); //this checks the sorted one, with binary search
        double puss_time = benchmark(print_until_ss, sorted, key_word); //this checks the sorted one, with binary search

        std::cout << _print_until << " Time: " << pu_time << "ms\n";
        std::cout << _print_until_s << " Time: " << pus_time << "ms\n";
        std::cout << _print_until_ss << " Time: " << pus_time << "ms" << std::endl;
    }
    while(std::cin.get(c) && c != 'q');
    termination_prompt();
}

void print_until(const std::vector<std::string>& vec, const std::string& quit) // used custom loop unrolling
{   
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == quit) return;
    }
}

void print_until_s(const std::vector<std::string>& vec, const std::string& quit)
{
    int left = 0;
    int right = vec.size() - 1;
    int mid = 0;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(vec[mid] == key_word) return;
        if(vec[mid] < key_word)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

void print_until_ss(const std::vector<std::string>& vec, const std::string& quit)
{
    int left = 0;
    int right = vec.size() - 1;
    int mid = 0;
    int count = 0 ;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(vec[mid] == key_word) 
        { 
            count ++; 
            int i = mid + 1;
            while(i < vec.size() && vec[i] == key_word)
            {
                count ++;
                i++;
            }

            i = mid - 1;
            while(i >= 0 && vec[i] == key_word)
            {
                count++;
                i--;
            }
            if(count >= 2)
            {
                return;
            }
        }

        if(vec[mid] < key_word)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}