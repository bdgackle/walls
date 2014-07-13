/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "creature.h"
#include "world.h"

namespace walls {

Creature::Creature(World* world, const MapLocation& location) :
    Object(world, location) {}

Creature::~Creature() {}

void Creature::move(int d_x, int d_y, int d_z)
{
    MapLocation new_loc = getLocation().getRelative(d_x, d_y, d_z);

    if ((getWorld()->getMap()->exists(new_loc)) &&
        !(getWorld()->getMap()->getBlock(new_loc)->getIsMovementBoundry()))
    {
        setLocation(new_loc);
    }
}

} // walls
