#include <iostream>
#include <fstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream ifs{"readFile.txt"};
    std::ofstream ofs{"outputFile.txt"};
    if(!ifs || !ofs) std::cout << "readFile.txt or outputFile.txt was not found\n" << std::flush;
    std::string input{""};
    while(ifs >> input)
    {
        for(char& c: input) c = std::tolower(c);
        ofs << input;
        input = "";
    }
}