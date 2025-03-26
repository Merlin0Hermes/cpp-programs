#include <string>

class Monster
{
public:
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

    Monster(Type type, std::string_view name, std::string_view roar, int hit_points)
    :m_type{ type }
    ,m_name{ name }
    ,m_roar{ roar }
    ,m_hit_points{ hit_points }
    { }


private:

    Type m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hit_points{};

};


int main()
{
	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };

	return 0;
}