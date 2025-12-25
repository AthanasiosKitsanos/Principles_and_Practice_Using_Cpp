#include "pch.h"
#include "models/readings.h"

#define f_end std::ios::end
#define f_start std::ios::beg

constexpr const char* raw_temps = "raw_temps.txt";

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<readings> r_vec;
    //Since we know the file has 50 entries, we reserve that much to avoid 50 allocations
    //There is an error in the file in purpose
    r_vec.reserve(50);
    std::ifstream ifs{raw_temps};
    if(!ifs)
    {
        std::cout << "Failed to open " << raw_temps << '\n' << std::flush;
        return 1;
    }

    {
        ifs.seekg(0, f_end);
        std::streamsize size{ifs.tellg()};
        ifs.seekg(0, f_start);

        char buffer[size + 1];
        ifs.read(buffer, size);
        buffer[size] = '\0';
        
        const char* start{buffer};
        const char* const end{buffer + size};
        double temperature{0};
        int hour{0};

        while(start < end)
        {
            while(!isdigit(*start)) ++start;
            if(start >= end) break;
            //since we skip spaces and letters, there is no need to do ec != std::errc{} check
            //and at the same time, the program can skip an invalid line
            auto result = std::from_chars(start, end, hour);
            start = result.ptr;
            while(!isdigit(*start)) ++start;
            result = std::from_chars(start, end, temperature);
            r_vec.emplace_back(temperature, hour);
            start = result.ptr;
        }
    }

    //there are 50 entries inside the file, in which one is invalid
    //meaning the size should be 49 and not 50
    std::cout << "Vector size: " << r_vec.size() << '\n';

    int m{0};
    for(const readings& r: r_vec)
    {
        m += r.temperature;
    }
    std::cout << "Mean: " << static_cast<float>(m) / r_vec.size() << '\n';
    if(r_vec.size() % 2 != 0) { m = r_vec[r_vec.size() / 2].temperature; }
    else { m = static_cast<float>((r_vec[r_vec.size() / 2].temperature + r_vec[r_vec.size() / 2 - 1].temperature)) / 2; }
    std::cout << "Median: " << m << '\n';
}