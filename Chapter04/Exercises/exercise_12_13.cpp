#include "headers.h"

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(0, 9);

    std::vector<int> dist_vector(4);

    {
        bool ready = false;

        while(!ready)
        {
            for(int i = 0; i < dist_vector.size(); i++)
            {
                dist_vector[i] = dist(gen);
            }

            ready = true;

            for(int i = 0; i < dist_vector.size() - 1; i++)
            {
                if(dist_vector[i] == dist_vector[i + 1])
                {
                    ready = false;
                    break;
                }
            }
        }
    }

    std::vector<int> input_vector(4);

    std::cout << "Enter 4 numbers between 0 and 9 (Press any character to stop)" << std::endl;

    while(true)
    {
        int num = 0;
        bool valid_input = true;

        for(int i = 0; i < 4; i++)
        {
            if(!(std::cin >> num))
            {
                valid_input = false;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            if(num < 0 || num > 9)
            {
                i = -1;
                std::cout << "Input out of range" << std::endl;
                continue;
            }

            input_vector[i] = num;
        }

        if(!valid_input)
        {
            std::cout << "Game terminated" << std::endl;
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
            std::cout << "You win" << std::endl;
            std::cout << "You" << '\t' << "PC" << std::endl;

            for(int i = 0; i < input_vector.size(); i++)
            {
                std::cout << input_vector[i] << '\t' << dist_vector[i] << std::endl;
            }
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }

        std::cout << bulls << " Bulls and " << cows << " Cows" << std::endl;
        std::cout << "\nTry again" << std::endl;
    }
    
    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}