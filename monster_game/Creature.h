#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <string_view>

class Creature
{
private:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_attack_damage{};
    int m_gold{};

};


#endif