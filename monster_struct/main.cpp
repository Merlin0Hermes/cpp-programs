#include <iostream>
#include <string>


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
    int health;
};