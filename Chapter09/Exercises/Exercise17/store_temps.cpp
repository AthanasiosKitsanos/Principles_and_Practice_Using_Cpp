#include "readings.h"
#include <charconv>
#include <iomanip>

constexpr const char* raw_temps = "raw_temps.txt";

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //We are using a string with allocated memory
    //to avoid allocation in case there are 5 characters or less
    std::string input;

    short counter{1}; //declare and initialize a counter to print how many raws in the file
    const char* start{input.data()}; //declare initialize a pointer that point to the start of the string
    const char* end{nullptr}; //declare initialize an end poitner that is null for now

    std::ofstream ofs{raw_temps};

    for(reading rd{}; std::getline(std::cin, input);)
    {
        end = start + input.size(); // initialize and point to the end of the string
        if(input == "exit") break;
        while(isspace(*start)) ++ start; //move the pointer to a valid character
        auto result = std::from_chars(start, end, rd.hour);
        if(result.ec != std::errc{})
        {
            std::cout << "There was problem reading the hour\n" << std::flush;
            continue;
        }
        ofs << counter++ << ' ';
        if(!rd.is_valid_hour()) //if an error occurs, it is printed in the file
        {
            std::cout << rd.error() << std::flush;
            ofs << rd.error(); 
            continue;
        }
        start = result.ptr;
        while(isspace(*start)) ++ start; //move the pointer to a valid character to read the temperature
        result = std::from_chars(start, end, rd.temperature);
        if(result.ec != std::errc{})
        {
            std::cout << "There was problem reading the temperature\n" << std::flush;
            continue;
        }
        ofs << "Hour: " << rd.hour << std::setw(16) << std::setprecision(2) << "Temperature: " << rd.temperature << '\n';
        start = input.data(); //reset the starting pointer
    }
}