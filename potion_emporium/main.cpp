#include <iostream>
#include <array>
#include <string_view>
#include <cstddef>


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

    constexpr std::array<std::string_view, max_potions> names{
        "healing", "mana", "speed", "invisibility",
    };

    constexpr std::array<int, max_potions> costs { 20, 30, 12, 50};
}

void shop()
{
    std::cout << "Here is our selection for today: ";
    for (std::size_t i {0}; i < Potion::max_potions; ++i)
    {
        std::cout << i << ") " << Potion::names[i] << " costs " << Potion::costs[i] << "\n"; 
    }
}

int main()
{
    shop();
    return 0;
}