#include <fstream>
#include <iostream>
#include <charconv>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::fstream file_stream;

    file_stream.open("input.txt");
    if(!file_stream)
    {
        std::cout << "Failed to open input.txt\n";
        return 1;
    }
    file_stream.seekg(0, std::ios::end);
    std::streamsize size = file_stream.tellg();
    file_stream.seekg(0, std::ios::beg);

    char input[size + 1];
    input[size] = '\0';

    {
        std::streambuf* sb = file_stream.rdbuf();
        sb->sgetn(input, size);
    }
    
    file_stream.close();

    const char* current = input;
    const char* const end = current + size;

    int sum{0};
    for(int num{0}; current < end;)
    {
        while(!isdigit(*current)) ++current;
        auto result = std::from_chars(current, end, num);
        if(result.ec != std::errc{}) std::cout << "Could not read number\n";
        sum += num;
        current = result.ptr;
    }

    file_stream.open("output.txt");
    file_stream << "Result: " << sum;
}