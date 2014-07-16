/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "creature.h"
#include "world.h"

namespace walls {

Creature::Creature(World* world, const MapLocation& location) :
    Object(world, location) {
    m_world->getMap()->getBlock(getLocation())->addCreature(this);
}

Creature::~Creature() {}

void Creature::die() {
    m_world->getMap()->getBlock(getLocation())->removeCreature(this);
    setIsDead();
}

void Creature::move(int d_x, int d_y, int d_z) {
    MapLocation old_loc = getLocation();
    MapLocation new_loc = old_loc.getRelative(d_x, d_y, d_z);

    if ((m_world->getMap()->exists(new_loc)) &&
        !(m_world->getMap()->getBlock(new_loc)->getIsMovementBoundry())) {
        setLocation(new_loc);
        m_world->getMap()->getBlock(old_loc)->removeCreature(this);
        m_world->getMap()->getBlock(new_loc)->addCreature(this);
    }
}

} // walls
