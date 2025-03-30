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
    void letter_guessed(char letter)
    {
        m_letters_guessed[(letter % 32) - 1] = true;
    }
    const std::vector<bool>& letters_guessed() const { return m_letters_guessed; }

private:
    std::vector<bool> m_letters_guessed {std::vector<bool>(26)};
    std::string m_word{ WordList::random_word() };
};


void display_state(const Session& session)
{
    std::vector<bool> guessed { session.letters_guessed() };

    std::cout << "\nThe word: ";
    for (const auto& a: session.word())
    {
        if (guessed[(a % 32) - 1])
            std::cout << a;
        else
            std::cout << "_";
    }
    std::cout << "\n";
}

char get_letter()
{
    char c {};
    while (true)
    {
        std::cout << "Enter you next letter: ";
        std::cin >> c;

        if (!std::cin) 
        {
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (c < 'a' || c > 'z')
        {
            std::cout << "That wasn't a valid input.  Try again.\n";
            continue;
        }

        return c;
    }
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    display_state(Session{});
    char letter {get_letter()};
    std::cout << "You entered: " << letter << "\n";
}