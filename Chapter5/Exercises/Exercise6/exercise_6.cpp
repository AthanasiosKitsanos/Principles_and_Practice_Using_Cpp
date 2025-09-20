#include "headers.h"

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(97, 122); // form a to z, no capital letters

    std::vector<char> dist_vector(4);

    {
        bool ready = false;

        while(!ready)
        {
            ready = true;

            dist_vector[0] = dist(gen);
            
            for(int i = 1; i < dist_vector.size(); i++)
            {
                dist_vector[i] = dist(gen);

                if(dist_vector[i - 1] == dist_vector[i])
                {
                    ready = false;
                    break;
                }
            }
        }
    }

    std::vector<char> input_vector(4);

    std::cout << "Enter 4 characters (not numbers) between a and z with no capitalization (Enter 'exit' to close the program)" << std::endl;

    while(true)
    {
        std::string exit = "";

        {
            bool is_ready = false;
            char c;

            while(!is_ready)
            {
                is_ready = true;
                
                for(int i = 0; i < input_vector.size(); i++)
                {    
                    std::cin >> c;

                    if(c < char(97) || c > char(122))
                    {
                        is_ready = false;
                        std::cerr << "Input out of range" << std::endl;
                        break;
                    }

                    exit += c;
                    input_vector[i] = c;
                    
                    for(int j = 0; j <= i; i++)
                    {
                        if(input_vector[i] == input_vector[j])
                        {
                            is_ready = false;
                            std::cout << "All characters must be different" << std::endl;
                            break;
                        }
                    }

                    if(!is_ready)
                    {
                        break;
                    }
                }
            }
        }

        if(exit == "exit")
        {
            break;
        }

        int bulls = 0;
        int cows = 0;

        for(int i = 0; i < input_vector.size(); i++)
        {
            for(int j = 0; j < dist_vector.size(); j++)
            {
                if(input_vector[i] == dist_vector[j])
                {
                    if(i == j)
                    {
                        bulls++;
                        continue;
                    }

                    cows++;
                }
            }
        }

        if(bulls == input_vector.size())
        {
            std::cout << "Yoou win" << std::endl;
            std::cout << "You" << '\t' << "PC" << std::endl;

            for(int i = 0; i < input_vector.size(); i++)
            {
                std::cout << input_vector[i] << '\t' << dist_vector[i] << std::endl;
            }
            
            break;
        }

        std::cout << bulls << " Bulls and " << cows << " Cows" << std::endl;
        std::cout << "\nTry again" << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}