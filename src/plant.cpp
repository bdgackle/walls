/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "plant.hpp"
#include "world.hpp"

namespace walls {

Plant::Plant(World* world, const MapLocation& location) :
    Object(world, location)
{
    m_world->getMap()->getBlock(getLocation())->addPlant(this);
}

Plant::~Plant() {}

void Plant::die()
{
    m_world->getMap()->getBlock(getLocation())->removePlant(this);
    setIsDead();
}

} // walls
