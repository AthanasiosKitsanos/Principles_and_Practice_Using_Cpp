#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

// Checks if 'c' is a letter, digit or -
bool is_word_char(char c)
{
    return isalnum(c) || c == '-';
}

// Pass the string you want to change, the word you want to be replaced and the word to take it's place
void replace_all(std::string& source, const std::string& from, const std::string& to)
{
    size_t pos{0};
    while((pos = source.find(from, pos))!= std::string::npos) // Finds the word you want to replace and returns it's starting position
    {
        source.replace(pos, from.size(), to); // Replaces from current position to the word's final letter position, with the new word
        pos += to.size(); // the new word's size is added to the position to continue searching if there is another reference to that word
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<std::string> words;
    for(std::string text{""}; std::getline(std::cin, text); text.clear())
    {
        if(text.empty())
        {
            std::cout << "Skip" << std::flush;
            continue;
        }
        if(text == "exit") return 0;
        for(char& c: text) c = std::tolower(c); // replaces all the letter with their lowercase ones

        // Replaces from the don't woth do not
        replace_all(text, "don't", "do not");
        replace_all(text, "can't", "cannot");
        replace_all(text, "cant", "cannot");
        // Create and reserve the same size as the original text to avoid allocations
        std::string final_text;
        final_text.reserve(text.size());

        // Find the position of the first letter in case we wrote a space or a punctuation
        size_t i{0};
        while(!isalpha(text[i])) ++i;

        // If the letter is valid we add it to the final_text
        for(; i <  text.size(); ++i)
        {
            if(is_word_char(text[i])) final_text += text[i];
            else final_text += ' ';
        }

        // Take the last position and find if there are spaces and erese them
        i = final_text.size() - 1;
        while(final_text[i] == ' ') --i;
        final_text.erase(i + 1);

        // we take each word and add it to the word list
        std::string word{""};
        for(i = 0; i < final_text.size(); ++i) 
        {
            if(!isspace(final_text[i])) word += final_text[i];
            else
            {
                words.emplace_back(std::move(word));
                word.clear();
            }
        }

        // Add the final word to the vector, since the isspace will not add it
        if(!word.empty())
        {
            words.emplace_back(std::move(word));
            word.clear();
        }

        // Write the result in the file
        if(!words.empty())
        {
            sort(words.begin(), words.end(), [](const std::string& a, const std::string& b){ return a < b; } );
            std::ofstream ofs{"multi_page.txt"};
            if(!ofs) std::cout << "File not found\n";
            else
            {
                for(i = 0; i < words.size() - 1; ++i)
                {
                    ofs << words[i] << '\n';
                }
                ofs << words[words.size() - 1];
                std::cout << "Text written" << std::endl;
            }
            words.clear();
        }
        else std::cout << "Empty list" << std::endl;
    }
}