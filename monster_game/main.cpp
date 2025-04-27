// a game where you fight monsters and collect as much gold as possible.
// stops when you die or reach level 20.
// implemented using inheritance

#include <iostream>

#include "Creature.h"
#include "Player.h"
#include "Monster.h"


void fight_monsters(Player& p)
{
	Monster m{Monster::random_monster()};

	std::cout << "You have encountered a " << m.name() << "(" << m.symbol() << ").\n";

	std::cout << "(R)un or (F)ight: ";
	char input{};
	std::cin >> input;

	
}

int main()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;

	Player player {name};
	std::cout << "Welcome, " << name << "\n";

	while (true)
	{
		
		fight_monsters(player);
	}


	return 0;
}