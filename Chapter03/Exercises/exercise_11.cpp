#include "headers.h"

int main()
{   
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);

    std::vector<std::string> game_vector = {"paper", "rock", "scissors"};

    std::cout << "--Rock, Paper, Scissors--" <<std::endl;

    std::cout << "Write rock, paper, or scissors." << std::endl;
    std::cout << "Write exit to close the program." << std::endl;

    int player_score = 0;
    int pc_score = 0;

    for(std::string input; std::getline(std::cin, input);)
    {
        if(input == "exit")
        {
            break;
        }

        int player_result = -1;

        for(int i = 0; i < game_vector.size(); i++)
        {
            if(input == game_vector[i])
            {
                player_result = i;
                break;
            }
        }

        if(player_result == - 1)
        {
            std::cout << "Please enter a valid input:" << std::endl;
            continue;
        }

        int pc_result = dist(gen);

        std::cout << "You: " << game_vector[player_result] << "\tPC: " << game_vector[pc_result] << std:: endl;

        switch(player_result)
        {
            case 0:
                if(pc_result == 1)
                {
                    player_score++;
                    std::cout << "You win" << std::endl;
                }
                else if(pc_result == 2)
                {
                    pc_score++;
                    std::cout << "You lose" << std::endl;
                }
                else
                {
                    std::cout << "It's a tie" << std::endl;
                }
                break;
            
            case 1:
                if(pc_result == 0)
                {
                    pc_score++;
                    std::cout << "You lose" << std::endl;
                }
                else if(pc_result == 2)
                {
                    player_score++;
                    std::cout << "You win" << std::endl;
                }
                else
                {
                    std::cout << "It's a tie" << std::endl;
                }
                break;

            case 2:
                if(pc_result == 0)
                {
                    player_score++;
                    std::cout << "You win" << std::endl;
                }
                else if(pc_result == 1)
                {
                    pc_score++;
                    std::cout << "You lose" << std::endl;
                }
                else
                {
                    std::cout << "It's a tie" << std::endl;
                }
                break;
        }

        std::cout << "Score: " << "Player - " << player_score << "\tPC - " << pc_score << std::endl;
    }

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}