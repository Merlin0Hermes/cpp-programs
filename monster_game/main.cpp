// a game where you fight monsters and collect as much gold as possible.
// stops when you die or reach level 20.
// implemented using inheritance

#include <iostream>
#include "Creature.h"
#include "Player.h"

int main()
{
    std::cout << "Enter you name: ";
    std::string name{};
    std::cin >> name;

    Player o{name};
    std::cout << "Welcome, " << name << "\n";
	std::cout << "You have " << o.health() << " health and are carrying " << o.gold() << " gold.\n";

	return 0;
}