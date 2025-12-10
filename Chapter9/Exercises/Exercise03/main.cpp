#include <iostream>
#include <fstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string output{""};
    {
        std::ifstream file{"disemvowels.txt"};
        if(!file) std::cout << "File not found\n";
        std::string input{""};
        std::getline(file, input);
        char c;
        for(short i = 0; i < input.length(); ++i)
        {
            c = input[i];
            switch(c)
            {
                case 'a': case 'A':
                case 'e': case 'E':
                case 'i': case 'I':
                case 'o': case 'O':
                case 'u': case 'U':
                case 'y': case 'Y':
                    break;
                default:
                    if(c != ' ' || output.back() != ' ')
                    {
                        output += c;
                    }
                    break;
            }
        }
    }
    std::ofstream file{"disemvowels.txt"};
    if(!file) std::cout << "File not found\n";
    file << output;
}