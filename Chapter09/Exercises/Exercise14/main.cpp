#include <fstream>
#include <iostream>
#include <iomanip>
#include <charconv>
#include <sstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream ifs{"input_file.txt", std::ios::binary};
    if(!ifs)
    {
        std::cout << "Failed to open input_file.txt\n";
        return 1;
    }
    std::ofstream ofs{"output_file.txt"};
    ifs.seekg(0, std::ios::end);
    std::streamsize size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    std::string text(size, '\0');
    ifs.read(text.data(), size);

    float num{0};
    const char* start = text.data();
    const char* const end = start + text.size();
    ofs << std::scientific << std::setprecision(8);
    short counter{0};
    while(start < end)
    {
        while(start < end - 1 && isspace(*start)) ++start;
        auto result = std::from_chars(start, end, num);
        if(result.ec != std::errc{})
        {
            std::cout << "There was a problem while reading a number" << std::endl;
            return 1;
        }
        start = result.ptr;
        ofs << std::setw(20) << std::left << num;
        ++counter;
        if(counter == 4)
        {
            ofs << '\n';
            counter = 0;
            continue;
        }
        else
        {
            ofs << ' ';
        }
    }
}