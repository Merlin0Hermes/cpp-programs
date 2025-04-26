#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

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

};

#endif