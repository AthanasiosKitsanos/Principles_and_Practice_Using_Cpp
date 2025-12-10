#include <iostream>
#include <fstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ifstream file("file.txt");
    if(!file) std::cout << "File not found\n";
    short count{1};
    for(std::string line; std::getline(file, line); line = "")
    {
        if(line.find("test") != std::string::npos)
        {
            std::cout << count << ". " << line << '\n';
        }
        ++count;
    }
}