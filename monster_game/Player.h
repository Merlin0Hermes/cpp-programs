#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Potion.h"
#include <iostream>

namespace  PlayerDefault 
{
    constexpr std::string_view name{"Unknown"};
    constexpr char symbol{'@'};
    constexpr int health{15};
    constexpr int attack_damage{1};
    constexpr int gold{0};
    constexpr int level{1};
}

namespace PlayerSetting
{
    constexpr int winning_level{20};
}

class Player: public Creature
{
private:
    int m_max_health{PlayerDefault::health};
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
        constexpr int heal_factor {3};
        ++m_level;
        ++m_attack_damage;
        add_health(m_max_health / heal_factor);
    }

    void add_health(int health)
    {
        int new_health {m_health + health};

        if (new_health > m_max_health)
            m_health = m_max_health;
        else
            m_health = new_health;
    }

    bool has_won(){ return m_level >= PlayerSetting::winning_level; }

    void drink_potion(const Potion& potion)
    {
        switch(potion.type())
        {
            case Potion::health:
                if (potion.size() == Potion::small)
                    add_health(2);
                else if (potion.size() == Potion::medium)
                    add_health(3);
                else if (potion.size() == Potion::large)
                    add_health(5);
                break;
            
            case Potion::strength:
                if (potion.size() == Potion::small)
                    m_attack_damage += 1;
                else if (potion.size() == Potion::medium)
                    m_attack_damage += 2;
                else if (potion.size() == Potion::large)
                    m_attack_damage += 3;
                break;

            case Potion::poison:
                if (potion.size() == Potion::small)
                    m_health -= 2;
                else if (potion.size() == Potion::medium)
                    m_health -= 5;
                else if (potion.size() == Potion::large)
                    m_health -= 10;
                break;
            
            case Potion::vigor:
                if (potion.size() == Potion::small)
                    m_max_health += 2;
                else if (potion.size() == Potion::medium)
                    m_max_health += 3;
                else if (potion.size() == Potion::large)
                    m_max_health += 4;
                break;

            default:
                std::cerr << "Invalid potion in drink_potion() in Player.h\n";
        }
    }

};

#endif
