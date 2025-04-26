// a game where you fight monsters and collect as much gold as possible.
// stops when you die or reach level 20.
// implemented using inheritance

#include <iostream>
#include "Creature.h"

int main()
{
	Creature o{ "orc", 'o', 4, 2, 10 };
	o.add_gold(5);
	o.reduce_health(1);
	std::cout << "The " << o.name() << " has " << o.health() << " health and is carrying " << o.gold() << " gold.\n";

	return 0;
}