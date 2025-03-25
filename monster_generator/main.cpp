#include <string>

enum class MonsterType
{
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    max_monster_types

};

class Monster
{
private:
    MonsterType type{};
    std::string name{"???"};
    std::string roar{"???"};
    int hit_points{};

};