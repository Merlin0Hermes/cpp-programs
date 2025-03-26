#include <string>
#include <string_view>
#include <iostream>

#include "../Random.h"

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


namespace MonsterGenerator
{
    std::string_view get_name()
    {
        int num { Random::get(0, 5) };
        switch (num)
        {
            case 0: return "Blarg";
            case 1: return "Moog";
            case 2: return "Pksh";
            case 3: return "Mort";
            case 4: return "Tyrn";
            case 5: return "Hans";

            default: return "???";

        }
    }

    std::string_view get_roar()
    {
        int num { Random::get(0, 5) };
        switch (num)
        {
            case 0: return "*ROAR*";
            case 1: return "*peep*";
            case 2: return "*squeal*";
            case 3: return "*whine*";
            case 4: return "*growl*";
            case 5: return "*burp*";

            default: return "???";

        }
    }


    Monster generate()
    {
        return Monster{ static_cast<Monster::Type>(Random::get(0, Monster::max_monster_types - 1))
            , get_name(), get_roar(), Random::get(1, 100) 
        };
    }
}


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
    std::cout << m_name << " the " << get_type_string(m_type);

    if (m_hit_points <= 0)
        std::cout << " is dead.\n";
    else
        std::cout << " has " << m_hit_points << " hit points and says " << m_roar << ".\n";
}


int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}