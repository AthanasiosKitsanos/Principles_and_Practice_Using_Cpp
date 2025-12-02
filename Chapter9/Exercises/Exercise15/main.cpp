#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ifstream ifs{"test_file.txt"};
    if(!ifs)
    {
        std::cout << "Failed to open test_file.txt\n";
        return 1;
    }
    ifs.seekg(0, std::ios::end);
    std::streamsize size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    std::string text(size, '\0');
    ifs.read(text.data(), size);
    short counts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char c{'\0'};
    for(short i{0}; i < 10; ++i)
    {
        for(const char& c: text)
        {
            if(isdigit(c))
            {
                if(i == c -'0') ++counts[i];
            }
        }
    }
    for(short i{0}; i < 10; ++i)
    {
        if(counts[i] > 0)
        {
            std::cout << "Number: " << i;
            if(counts[i] > 1) std::cout << std::setw(5) << counts[i];
            std::cout << '\n';
        }
    }
}