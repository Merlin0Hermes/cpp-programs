#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <string_view>

class Creature
{
public:
    const std::string& name() const { return m_name; }
    char symbol() const { return m_symbol; }
    int health() const { return m_health; }
    int attack_damage() const { return m_attack_damage; }
    int gold() const { return m_gold; } 

private:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_attack_damage{};
    int m_gold{};

};


#endif