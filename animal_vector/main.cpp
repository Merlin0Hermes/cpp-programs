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

    const std::vector legs {2, 4, 4, 4, 2, 0};
}


int main()
{
     // number of legs of each animal

    assert(Animals::legs.size() == Animals::max_animals);

    std::cout << "Elephant has " << Animals::legs[Animals::elephant] << " legs.\n";

    return 0;
}