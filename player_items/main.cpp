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

    int sum{};
    for (auto item: inventory)
        sum += item;

    std::cout << "You have " << sum << " total items\n";

    return 0;

}