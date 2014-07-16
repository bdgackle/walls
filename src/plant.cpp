/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "plant.h"
#include "world.h"

namespace walls {

Plant::Plant(World* world, const MapLocation& location) :
    Object(world, location) {
    m_world->getMap()->getBlock(getLocation())->addPlant(this);
}

Plant::~Plant() {}

void Plant::die() {
    m_world->getMap()->getBlock(getLocation())->removePlant(this);
    setIsDead();
}

} // walls
