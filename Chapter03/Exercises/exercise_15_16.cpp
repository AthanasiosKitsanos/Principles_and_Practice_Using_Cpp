#include "headers.h"

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    
    {
        std::cout << "Exercise 15" <<std::endl;

        std::uniform_int_distribution dist(1, 100);

        std::vector<int> vec;

        for(int i = 0; i < 100; i += 2)
        {
            vec.push_back(dist(gen));
            vec.push_back(dist(gen));
        }

        std::unordered_map<int, int> freq;

        for(int num: vec)
        {
            freq[num]++;
        }

        int mode_count = 0;
        int mode_number = 0;

        for(const std::pair<const int, int>& p : freq)
        {
            if(p.second > mode_count)
            {
                mode_count = p.second;
                mode_number = p.first;
            }   
        }
            
        std::cout << "Mode: " << mode_count << '\t' << "Number: " << mode_number << std::endl;
    }

    {
        std::cout << "\nExercise 16" << std::endl;
        std::uniform_int_distribution dist(0, 3);

        std::vector<std::string> string_list = {"Mike", "Theo", "Sabrina", "Redmington"};

        std::vector<std::string> seq_vec;

        for(int i = 0; i < 100; i += 5)
        {
            seq_vec.push_back(string_list[dist(gen)]);
            seq_vec.push_back(string_list[dist(gen)]);
            seq_vec.push_back(string_list[dist(gen)]);
            seq_vec.push_back(string_list[dist(gen)]);
            seq_vec.push_back(string_list[dist(gen)]);
        }

        std::unordered_map<std::string, int> freq;

        for(std::string name : seq_vec)
        {
            freq[name]++;
        }

        std::string mode_name = "";
        int mode_count = 0;

        for(const std::pair<const std::string, int>& p : freq)
        {
            if(p.second > mode_count)
            {
                mode_count = p.second;
                mode_name = p.first;
            }
        }

        std::cout << "Name: " << mode_name << '\t' << "Mode: " << mode_count << std::endl;
    }

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0 ;
}