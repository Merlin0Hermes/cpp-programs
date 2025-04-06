#include <iostream>
#include <array>
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

    Player(std::string_view name): m_name{name} { }

    std::string_view name() const { return m_name; };
    int gold() const { return m_gold; }

private:
    std::string m_name{"???"};
    int m_gold{Random::get(80, 120)};
    std::vector<Potion::Type> m_potions{};
};


int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    std::cout << "Enter you name: ";
    std::string name{};
    std::cin >> name;

    Player player{name};

    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n"; 

    shop();

    return 0;
}