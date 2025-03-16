#include <iostream>
#include <string>
#include <string_view>


enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,

};


struct Monster
{
    std::string name;
    MonsterType type;
    int health;
};


std::string_view get_monster_type_string(MonsterType monster)
{
    using enum MonsterType;
    switch (monster) 
    {
        case ogre: return "Ogre";
        case dragon: return "Dragon";
        case orc: return "Orc";
        case giant_spider: return "Giant Spider";
        case slime: return "Slime";

        default: return "???";
    }
}


std::ostream& operator<<(std::ostream& out, MonsterType mt)
{
    out << get_monster_type_string(mt);
    return out;
}


void print_monster(Monster monster)
{
    std::cout << "This " << monster.type << " is named " << monster.name << " and has " << monster.health << " health.\n";
}