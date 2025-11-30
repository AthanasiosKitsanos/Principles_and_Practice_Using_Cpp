#include <fstream>
#include <iostream>
#include <sstream>

void error(const char* input)
{
    std::cout << "Failed to open " << input << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::ifstream ifs{"test_file.txt"};
    if(!ifs)
    {
        error("test_file.txt");
        return 1;
    }
    std::string text{""};
    std::ostringstream oss;
    oss << ifs.rdbuf();
    text = std::move(oss.str());
    for(const char& c: text)
    {
        if(iscntrl(c))
        {
            switch (c)
            {
                case '\b':
                    std::cout << "<backspace>: ";
                    break;
                case '\f':
                    std::cout << "<form feed>: ";
                    break;
                case '\t':
                    std::cout << "<tab>: ";
                    break;
                case '\r':
                    std::cout << "<carriage return>: ";
                    break;
            }
            std::cout << "constrol\n";
            continue;
        }
        std::cout << c;
        if(isprint(c))
        {
            if(isalpha(c))
            {
                std::cout << ": is letter, alnum, print, graph";
                if(isxdigit(c)) std::cout << ", hex";
                std::cout << (isupper(c) ? ", upper" : ", lower") << '\n';
            }
            else if(isdigit(c)) std::cout << ": digit, alnum, print, graph, hex\n";
            else if(ispunct(c)) std::cout << ": punc, print, graph\n";
            else std::cout << ": space, print\n";
        }
    }
    std::cout << std::flush;
}