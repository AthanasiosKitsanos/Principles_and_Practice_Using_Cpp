#include <iostream>
#include <fstream>
#include <sstream>

void error(const char* input) { std::cout << "Failed to open " << input << std::endl; }

int main()
{
    std::ios::sync_with_stdio(false);
    std::string text{""};
    {
        std::ifstream ifs{"test_file.txt"};
        if(!ifs) error("test_file.txt");
        std::ostringstream oss;
        oss << ifs.rdbuf();
        text = std::move(oss.str());
    }
    
    
    std::ofstream ofs{"test_file.txt"};
    if(!ofs) error("test_file.txt");
    int word_back{0};
    for(int word_start(text.length() - 1); word_start >= 0; --word_start)
    {
        while(word_start >= 0 && isspace(text[word_start])) --word_start; // skip the withespaces in case the file ends with a whitespace
        word_back = word_start; // Save the index where a word ends
        while(word_start >= 0 && !isspace(text[word_start])) --word_start; // skip to the whitespace in front of the word, meaning that the start will point to a whitespace
        std::string_view word(text.data() + word_start + 1, word_back - word_start);
        ofs << word << ' ';
    }
}