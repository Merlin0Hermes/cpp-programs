// A game similar to hangman

#include <iostream>
#include <vector>
#include <string_view>
#include "../Random.h"

namespace WordList
{
    const std::vector<std::string_view> words {"mystery", "broccoli","account", "almost", "spaghetti", "opinion", "beautiful",
        "distance", "luggage"};
    


    std::string_view random_word()
    {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
    
}

class Session
{
public:
    std::string_view word() { return m_word; }
private:
    std::string m_word{ WordList::random_word() };
};




int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    std::cout << "The word is: " << WordList::random_word() << "\n";
}