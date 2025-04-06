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
private:
    std::string m_name{"???"};
    std::vector<Potion::Type> m_potions{};
    int gold{};
};


int main()
{
    shop();
    return 0;
}