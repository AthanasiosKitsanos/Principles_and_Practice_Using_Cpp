#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for(std::string input{""}; std::getline(std::cin, input); input.clear()) //since we are using std::getline(), the '\n' character does not appear in the input
    {
        if(input == "exit") break;
        for(const char& c: input)
        {
            if(iscntrl(c))
            {
                switch(c)
                {
                    case '\b':
                        std::cout << "<Backspace>: ";
                        break;
                    case '\f':
                        std::cout << "<Form Feed: ";
                        break;
                    case '\t':
                        std::cout << "<Tab>: ";
                        break;
                    case '\r':
                        std::cout << "<Carriage Return>: ";
                        break;
                }
                std::cout << "control\n";
            }
            if(isprint(c))
            {
                if(isalpha(c))
                {
                    std::cout << c << ": letter, alnum, print, graph";
                    if(isxdigit(c)) std::cout << ", hex";
                    std::cout << (isupper(c) ? ", upper" : ", lower") << '\n';
                    continue;
                }
                if(isdigit(c))
                {
                    std::cout << c << ": digit, alnum, print, graph, hex\n";
                    continue;
                }
                if(ispunct(c))
                {
                    std::cout << c << ": punc, print, graph\n";
                    continue;
                }
                std::cout << "' ': space, print\n";
                continue;
            }
        }
        std::cout << std::endl;
    }
}