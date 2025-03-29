#include <vector>
#include <iostream>
#include <cassert>

namespace Animals
{
    enum Animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,

        max_animals
    };
}


int main()
{
    std::vector legs {2, 4, 4, 4, 2, 0}; // number of legs of each animal

    assert(legs.size() == Animals::max_animals);

    std::cout << "Elephant has " << legs[Animals::elephant] << " legs.\n";

    return 0;
}