#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<std::string> word_list;
    const char* file_name = "file1.txt";

    std::ifstream ifs{file_name, std::ios::binary};
    if(!ifs)
    {
        std::cout << "Unable to open " << file_name << '\n';
        return 1;
    }
    ifs.seekg(0, std::ios::end);
    std::streamsize size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    //create a scope to free the stack memory from the temporarly variables
    {
        const char* current = nullptr;
        const char* end = nullptr;
        short len{0};
        
        {
            char buffer[size + 1];
            buffer[size] = '\0';
            ifs.read(buffer, size);
            ifs.close();

            current = buffer;
            end = current + size;
            while(current < end)
            {
                while(isspace(*current)) ++current;
                while(isalpha(*current))
                {
                    ++current;
                    ++len;
                }
                std::string_view word(current - len, len);
                word_list.emplace_back(word);
                len = 0;
            }
        }
        file_name = "file2.txt";
        ifs.open(file_name, std::ios::binary);
        if(!ifs)
        {
            std::cout << "Could not find " << file_name << '\n';
            return 1;
        }
        ifs.seekg(0, std::ios::end);
        size = ifs.tellg();
        ifs.seekg(0, std::ios::beg);
        char array[size + 1];
        array[size] = '\0';
        ifs.read(array, size);
        ifs.close();

        current = array;
        end = current + size;
        while(current < end)
        {
            while(isspace(*current)) ++current;
            while(isalpha(*current))
            {
                ++current;
                ++len;
            }
            std::string_view word(current - len, len);
            word_list.emplace_back(word);
            len = 0;
        }
    } //end of scope
    std::sort(word_list.begin(), word_list.end(), [](const std::string& a, const std::string& b){ return a < b; });
    size = word_list.size();
    std::ofstream ofs{"sorted_result.txt"};
    for(size_t i = 0; i < size - 1; ++i)
    {
        ofs << word_list[i] << ' ';
    }
    ofs << word_list[size - 1];
}