#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

namespace  PlayerDefault 
{
    constexpr std::string_view name{"Unknown"};
    constexpr char symbol{'@'};
    constexpr int health{10};
    constexpr int attack_damage{1};
    constexpr int gold{0};
    constexpr int level{1};
    constexpr int winning_level{20};
}


class Player: public Creature
{
private:
    int m_level{PlayerDefault::level};

public:
    Player(std::string_view name = PlayerDefault::name, char symbol = PlayerDefault::symbol,
            int health = PlayerDefault::health, int attack_damage = PlayerDefault::attack_damage,
            int gold = PlayerDefault::gold)
    :Creature(name, symbol, health, attack_damage, gold)
    {
    }

    int level() const {return m_level; }

    void level_up() // increase player's level and attack damage
    {
        ++m_level;
        ++m_attack_damage;
    }

    bool has_won(){ return m_level == PlayerDefault::winning_level; }

};

#endif
