// A game similar to hangman

#include <iostream>
#include <vector>
#include <string_view>
#include "../Random.h"

namespace WordList
{
    const std::vector<std::string_view> words {"mystery", "broccoli","account", "almost", "spaghetti", "opinion", "beautiful",
        "distance", "luggage"};
    
}

std::string_view random_word()
{
    return WordList::words[Random::get<std::size_t>(0, WordList::words.size() - 1)];
}


int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    std::cout << "The word is: " << random_word() << "\n";
}