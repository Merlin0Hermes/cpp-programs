#include <cstddef>
#include <ostream>
#include <vector>
#include <iostream>
#include <cassert>

namespace Items
{
    enum Type
    {
        health_potion,
        torch,
        arrow,

        max_items
    };
}

std::string_view item_to_string_singular(Items::Type item)
{
    using namespace Items;
    switch (item) 
    {
        case health_potion: return "health potion";
        case torch:         return "torch";
        case arrow:         return "arrow";
        
        default:            return "???";
    }
}

std::string_view item_to_string_plural(Items::Type item)
{
    using namespace Items;
    switch (item) 
    {
        case health_potion: return "health potions";
        case torch:         return "torches";
        case arrow:         return "arrows";
        
        default:            return "???";
    }
}


void print_items(const std::vector<int>& inventory)
{
    for (std::size_t i{0}; i < inventory.size(); ++i)
    {
        std::cout << "You have " << inventory[i] << " "; 
        if (inventory[i] > 1)
            std::cout << item_to_string_plural(static_cast<Items::Type>(i));
        else 
            std::cout << item_to_string_singular(static_cast<Items::Type>(i));

        std::cout << "\n";
    }
}


int main()
{
    std::vector<int> inventory {1, 5, 10};

    assert(inventory.size() == Items::max_items);

    print_items(inventory);

    int sum{};
    for (auto item: inventory)
        sum += item;

    std::cout << "You have " << sum << " total items\n";

    return 0;

}