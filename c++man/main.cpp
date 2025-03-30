// A game similar to hangman

#include <cctype>
#include <csignal>
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
    enum State
    {
        ongoing,
        win, 
        lose,
    };

    Session(int max=6): m_guesses { max } 
    { }

    // getters
    std::string_view word() const { return m_word; }
    int guess_remaining() const { return m_guesses; }
    std::vector<char> get_wrong_guesses() const { return m_wrong_guesses; }
    const std::vector<bool>& letters_guessed() const { return m_letters_guessed; }

    // functions to update and return guessed letters
    void set_guessed(char letter); 
    bool guessed(char letter) const;
    

private:
    std::string m_word{ WordList::random_word() };
    std::vector<bool> m_letters_guessed {std::vector<bool>(26)};
    int m_guesses {6};
    std::vector<char> m_wrong_guesses { };

    Session::State utility() const;
    void set_wrong_guess(char letter); // helper function for set_guessed(char letter)
};


bool Session::guessed(char letter) const
{
    return m_letters_guessed[(letter % 32) - 1];
}


void Session::set_guessed(char letter)
{
    m_letters_guessed[(letter % 32) - 1] = true;
    set_wrong_guess(letter);
}


void Session::set_wrong_guess(char letter)
{
    for (auto a: m_word)
    {
        if (a == letter)
            return;
    }
    --m_guesses;
    m_wrong_guesses.push_back(letter);
}

Session::State Session::utility() const
{
    if (guess_remaining() <= 0)
        return Session::lose;
    for (const auto& a: m_word)
    {
        if (!guessed(a))
        {
            return Session::ongoing;
        }
    }
    return Session::win;
}

void display_state(const Session& s)
{

    std::cout << "\nThe word: ";

    bool word_known { true };
    for (const auto& a: s.word())
    {
        if (s.guessed(a))
            std::cout << a;
        else
        {
            std::cout << "_";
            word_known = false;
        }
            
    }

    std::cout << "\tWrong guesses: ";
    for (int i {0}; i < s.guess_remaining(); ++i)
    {
        std::cout << "+";
    }
    for (const auto& a: s.get_wrong_guesses())
    {
        std::cout << a;
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
    while (session.guess_remaining() != 0)
    {
        display_state(session);
        char letter {get_guess(session)};
        session.set_guessed(letter);      
    }
    display_state(session);

}