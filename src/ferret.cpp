/**
 *  @author Barry Gackle
 */

// C Standard Library
#include "stdlib.h"

// Internal Headers
#include "ferret.h"
#include "block.h"
#include "world.h"

namespace walls {

Ferret::Ferret(World* world, const MapLocation& location) :
    Creature(world, location) {}

Ferret::~Ferret() {}

void Ferret::update(int time)
{
    Object::update(time);

    int dir = rand() % 4;

    if (dir == 0)
        move(-1, 0, 0);
    else if (dir == 1)
        move(1, 0, 0);
    else if (dir == 2)
        move(0, -1, 0);
    else if (dir == 3)
        move(0, 1, 0);
}

char Ferret::getDisplayChar() const
{
    return 'f';
}

} // walls
