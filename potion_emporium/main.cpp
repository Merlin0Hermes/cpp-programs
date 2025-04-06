#include <iostream>
#include <array>
#include <limits>
#include <string_view>
#include <cstddef>
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


class Player
{
public:
    explicit Player(std::string_view name): m_name{name} { }

    std::string_view name() const { return m_name; };
    int gold() const { return m_gold; }
    int inventory(Potion::Type p) const { return m_inventory[p]; }

    bool buy(Potion::Type p)
    {
        if ((m_gold - Potion::costs[p]) >= 0)
        {
            m_gold -= Potion::costs[p];
            ++m_inventory[p];
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
        std::cin >> choice;

        if (!std::cin)
        {
            std::cout << "That is an invalid input.  Try again: ";
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

        int val { char_to_int(choice) };
        if (val >=0 && val < Potion::max_potions)
            return static_cast<Potion::Type>(char_to_int(choice));

        std::cout << "I didn't understand what you said.  Try again: ";
    }       
}

void print_inventory(const Player& player)
{
    std::cout << "\nYour inventory contains:\n";
    for (const auto& p: Potion::types)
    {
        if (player.inventory(p) > 0)
            std::cout << player.inventory(p) << "x potion of " << Potion::names[p] << "\n";
    }
    std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}


void shop(Player& player)
{
    while (true)
    {
        std::cout << "Here is our selection for today: \n";
        for (const auto& p: Potion::types)
            std::cout << p << ") " << Potion::names[p] << " costs " << Potion::costs[p] << "\n"; 

        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        Potion::Type potion { get_potion() }; 

        if (potion == Potion::max_potions)
            return;
        
        if (player.buy(potion))
            std::cout << "You purchased a potion of " << Potion::names[potion] 
                <<  ".  You have " << player.gold() << " gold left.\n";
        else 
            std::cout << "You can not afford that.\n";
        
        std::cout << '\n';
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

    shop(player);

    print_inventory(player);

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

    return 0;
}