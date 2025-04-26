#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <string_view>

class Creature
{
public:
    // getters
    const std::string& name() const { return m_name; }
    char symbol() const { return m_symbol; }
    int health() const { return m_health; }
    int attack_damage() const { return m_attack_damage; }
    int gold() const { return m_gold; } 


    void reduce_health(int n) {m_health -= n; } // reduces creature's health by n 
    bool is_dead() const { return m_health <= 0; } // monster is dead if health <= 0
    void add_gold(int gold) { m_gold += gold; } // adds gold

private:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_attack_damage{};
    int m_gold{};

};


#endif