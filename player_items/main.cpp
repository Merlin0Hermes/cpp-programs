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

std::string_view item_to_string(Items::Type item)
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


std::ostream& operator<<(std::ostream& out, Items::Type item)
{
    out << item_to_string(item);
    return out;
}


void print_items(const std::vector<int>& inventory)
{
    for (int i{0}; i < inventory.size(); i++)
    {
        std::cout << "You have " << inventory[i] << " " << static_cast<Items::Type>(i);

        if (inventory[i] > 1)
            std::cout << "s";
        
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