// A game similar to hangman

#include <cctype>
#include <iostream>
#include <vector>
#include <string_view>
#include <limits>
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
    std::string_view word() const { return m_word; }
private:
    std::string m_word{ WordList::random_word() };
};


void display_state(const Session& session)
{
    std::cout << "\nThe word: ";
    for (const auto& a: session.word())
        std::cout << "_";
    std::cout << "\n";
}

char get_letter()
{
    char letter {};
    while (true)
    {
        std::cout << "Enter you next letter: ";
        std::cin >> letter;

        if (!std::cin || !std::isalpha(letter)) 
        {
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else 
            break;
    }
    std::cout << "You entered: " << letter << "\n";
    return letter;
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    display_state(Session{});
    get_letter();
}