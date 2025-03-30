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
    void set_guessed(char letter)
    {
        m_letters_guessed[(letter % 32) - 1] = true;
    }
    bool guessed(char letter) const
    {
        return m_letters_guessed[(letter % 32) - 1];
    }
    const std::vector<bool>& letters_guessed() const { return m_letters_guessed; }

private:
    std::vector<bool> m_letters_guessed {std::vector<bool>(26)};
    std::string m_word{ WordList::random_word() };
};


void display_state(const Session& session)
{

    std::cout << "\nThe word: ";
    for (const auto& a: session.word())
    {
        if (session.guessed(a))
            std::cout << a;
        else
            std::cout << "_";
    }
    std::cout << "\n";
}

char get_guess(const Session& s)
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

        if (s.guessed(c))
        {
            std::cout << "You already guessed that word.  Try again.\n";
            continue;
        }

        return c;
    }
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    Session session{};
    while (true)
    {
        display_state(session);
        char letter {get_guess(session)};
        session.set_guessed(letter);      
    }

}