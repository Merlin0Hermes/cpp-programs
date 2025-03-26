#include <string>
#include <string_view>
#include <iostream>

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

    std::string_view get_type_string(Type);
    void print();


private:

    Type m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hit_points{};

};


std::string_view Monster::get_type_string(Type type)
{
    switch (type)
    {
        case dragon: return "dragon";
        case goblin: return "goblin";
        case ogre: return "ogre";
        case orc: return "orc";
        case skeleton: return "skeleton";
        case troll: return "troll";
        case vampire: return "vampire";
        case zombie: return "zombie";

        default: return "???";

    }
}

void Monster::print()
{
    if (m_hit_points <= 0)
    {
        std::cout << m_name << " the " << m_type << " is dead.\n";
        return;
    }

    std::cout << m_name << " the " << m_type << " has " 
        << m_hit_points << " hit points and says " << m_roar << "\n";
}


int main()
{
	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

	return 0;
}