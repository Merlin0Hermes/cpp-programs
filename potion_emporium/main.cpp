#include <iostream>
#include <array>
#include <limits>
#include <string_view>
#include <cstddef>
#include <vector>
#include "../Random.h"

namespace Potion
{
    enum Type : std::size_t
    {
        healing, 
        mana,
        speed, 
        invisibility,

        max_potions
    };

    constexpr std::array<Type, max_potions> types {healing, mana, speed, invisibility};

    constexpr std::array<std::string_view, max_potions> names{
        "healing", "mana", "speed", "invisibility",
    };

    constexpr std::array<int, max_potions> costs { 20, 30, 12, 50};
}

void shop()
{
    std::cout << "Here is our selection for today: \n";
    for (const auto& p: Potion::types)
        std::cout << p << ") " << Potion::names[p] << " costs " << Potion::costs[p] << "\n"; 

}


class Player
{
public:

    explicit Player(std::string_view name): m_name{name} { }

    std::string_view name() const { return m_name; };
    int gold() const { return m_gold; }
    int inventory(Potion::Type p) { return m_inventory[p]; }

    bool buy(Potion::Type p)
    {
        if ((m_gold - Potion::costs[p]) >= 0)
        {
            m_gold -= Potion::costs[p];
            return true;
        }
        return false;
    }

private:
    static constexpr int min_gold{80};
    static constexpr int max_gold {120};

    std::string m_name{"???"};
    int m_gold{Random::get(min_gold, max_gold)};
    std::array<int, Potion::max_potions> m_inventory{};
};

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int char_to_int(char c)
{
    return c - '0';
}

Potion::Type get_potion()
{
    while (true)
    {
        char choice{};
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        std::cin >> choice;

        if (!std::cin)
        {
            std::cin.clear();
            ignore_line();
            continue;
        }

        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cout << "I didn't understand what you said.  Try again: ";
            ignore_line();
            continue;
        }

        if (choice == 'q')
            return Potion::max_potions;


        return static_cast<Potion::Type>(char_to_int(choice));
    }   
}


int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    std::cout << "Enter you name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    Player player{name};

    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n"; 

    shop();

    return 0;
}