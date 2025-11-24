#include <iostream>
#include <charconv>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(std::string input{""}; std::getline(std::cin, input); input = "")
    {
        int buffer{0};
        if(input == "exit") break;
        if(isdigit(input[0]))
        {
            if(input[0] == '0')
            {
                char c = input[1];
                switch(c)
                {
                    case 'x':
                        {
                            auto fchar = std::from_chars(input.data() + 2, input.data() + input.size(), buffer, 16);
                            if(fchar.ec != std::errc{}) std::cout << "Invalid input" << std::endl;
                            std::cout << input << " hexadecimal converts to " << std::dec << buffer << " decimal" << std::endl;
                        }
                        break;
                    default:
                        if(isdigit(c))
                        {
                            auto fchar = std::from_chars(input.data() + 1, input.data() + input.size(), buffer, 8);
                            if(fchar.ec != std::errc{}) std::cout << "Invalid input" << std::endl;
                            std::cout << input << " octal converts to " << std::dec << buffer << " decimal" << std::endl;
                        }
                        else std::cout << "Wrong input" << std::endl;
                        break;
                }
                continue;
            }
            auto fchar = std::from_chars(input.data(), input.data() + input.size(), buffer, 10);
            if(fchar.ec != std::errc{}) std::cout << "Invalid input" << std::endl;
            std::cout << input << " decimal converts to " << std::dec << buffer << " decimal" << std::endl;
        }
        else
        {
            std::cout << "Wrong input" << std::endl;
        }
    }
    std::cin.get();
}