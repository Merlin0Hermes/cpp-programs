// a game where you fight monsters and collect as much gold as possible.
// stops when you die or reach level 20.
// implemented using inheritance

#include <iostream>
#include <cctype>

#include "../Random.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"


void attack_monster(Player& p, Monster& m)
{
	if (p.is_dead())
		return;


	std::cout << "You hit the " << m.name() << " for " << m.attack_damage() << " damage.\n";
	m.reduce_health(p.attack_damage());

	if (m.is_dead())
	{
		std::cout << "You killed the " << m.name() << ".\n";
		p.level_up();
		std::cout << "You are now level " << p.level() << ".\n";
		std::cout << "Your health is restored.\n";
		std::cout << "You found " << m.gold() << "gold." << "\n";
		p.add_gold(m.gold());
		return;
	}
}


void attack_player(Player& p, const Monster&m)
{
	if (m.is_dead())
		return;

	std::cout << "The " << m.name() << " hit you for " << m.attack_damage() << " damage.\n";
	p.reduce_health(m.attack_damage());
}


void fight_monster(Player& p)
{
	Monster m{Monster::random_monster()};

	std::cout << "You have encountered a " << m.name() << "(" << m.symbol() << ").\n";

	while (!p.is_dead() && !m.is_dead() && !p.has_won())
	{
		std::cout << "(R)un or (F)ight: ";
		char input{};
		std::cin >> input;

		if (std::toupper(input) == 'F')
		{
			attack_monster(p, m);
			attack_player(p, m);
		}
		else if (std::toupper(input) == 'R')
		{
			if (Random::get(0, 1) == 0)
			{
				std::cout << "You failed to flee.\n";
				attack_player(p, m);
			}
			else
			{
				std::cout << "You successfully fled.\n";
				return;
			}
		}
	}
	
}

int main()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;

	Player player {name};
	std::cout << "Welcome, " << name << "\n";

	while (!player.is_dead() && !player.has_won())
	{
		fight_monster(player);
		std::cout << "\n";
	}

	if (player.is_dead())
	{
		std::cout << "You died at level " << player.level() << " with " << player.gold() << " gold.\n";
		std::cout << "Too bad you can’t take it with you!\n";
	}
	else if (player.has_won())
	{
		std::cout << "You win the game with " << player.gold() << " gold!\n";
	}


	return 0;
}