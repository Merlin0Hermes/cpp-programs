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
        goblin,
        slime,

        max_types
    };

    explicit Monster(Type type)
    :Creature{monsters[type]}
    {
    }

    static Type random_monster()
    {
        return static_cast<Type>(Random::get(0, max_types - 1));
    }

private:
    static inline Creature monsters[] {
        Creature{"dragon", 'D', 25, 8, 100},
        Creature{"orc", 'o', 10, 3, 35},
        Creature{"goblin", 'g', 5, 2, 25},
        Creature{"slime", 's', 2, 1, 10},
    };


};

#endif