// a game where you fight monsters and collect as much gold as possible.
// stops when you die or reach level 20.
// implemented using inheritance

#include <iostream>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	Monster m{ Monster::Type::orc };
	std::cout << "A " << m.name() << " (" << m.symbol() << ") was created.\n";

	return 0;
}