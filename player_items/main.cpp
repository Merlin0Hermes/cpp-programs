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

int main()
{
    std::vector<int> inventory {1, 5, 10};

    assert(inventory.size() == Items::max_items);

    std::cout << "You have " << inventory.size() << " total items\n";

    return 0;

}