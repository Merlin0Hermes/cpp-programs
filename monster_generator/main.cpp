#include <string>

class Monster
{

    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types,
           
    };

private:
    Type type{};
    std::string name{"???"};
    std::string roar{"???"};
    int hit_points{};

};