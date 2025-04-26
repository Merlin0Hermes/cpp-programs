#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "../Random.h"

class Monster: public Creature
{
public:
    enum Type 
    {
        dragon,
        orc,
        slime,

        max_types
    };

    explicit Monster(Type type)
    :Creature{monsters[type]}
    {
    }

    static Type random_monster()
    {
        return static_cast<Type>(Random::get(0, static_cast<int>(max_types) - 1));
    }

private:
    static inline Creature monsters[] {
        Creature{"dragon", 'D', 20, 4, 100},
        Creature{"orc", 'o', 4, 2, 25},
        Creature{"slime", 's', 1, 1, 10},
    };


};

#endif