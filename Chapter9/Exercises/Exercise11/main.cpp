#include <iostream>
#include <fstream>

void error(const char* name) { std::cout << "Failed to open " << name << std::endl; }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string text{""};

    // Take the input from the file and close it
    {
        std::ifstream ifs{"test_file.txt"};
        if(!ifs) error("test_file.txt");
        std::getline(ifs, text);
    }
    
    // Reverse the string
    size_t end{0};
    char temp{'\0'};
    for(size_t start{0}; start < text.size() / 2; ++start)
    {
        end = text.size() - start - 1;
        temp = text[start];
        text[start] = text[end];
        text[end] = temp;
    }

    //output the rearranged string back to the file
    std::cout << text << '\n';
    std::ofstream ofs("test_file.txt");
    if(!ofs) error("test_file.txt");
    ofs << text;
}