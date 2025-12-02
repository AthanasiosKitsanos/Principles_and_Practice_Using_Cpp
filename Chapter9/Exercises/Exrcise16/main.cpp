#include <iostream>
#include <fstream>
#include <charconv>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ifstream ifs{"test_file.txt"};
    if(!ifs)
    {
        std::cout << "Failed to open test_file.txt";
        return 1;
    }
    ifs.seekg(0, std::ios::end);
    std::streamsize size{ifs.tellg()};
    ifs.seekg(0, std::ios::beg);
    char buffer[size + 1];
    ifs.read(buffer, size);
    buffer[size] = '\0';
    const char* start = buffer;
    const char* const end = buffer + size;
    short sum{0};
    for(short current{0}; start < end;)
    {
        while(start < end && !isdigit(*start)) ++start;
        auto result{std::from_chars(start, end, current)};
        if(result.ec != std::errc{})
        {
            std::cout << "Problem with char convertion\n";
            return 1;
        }
        start = result.ptr;
        sum += current;
    }
    std::cout << "Summary: " << sum << '\n';
}