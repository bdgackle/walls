/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "plant.h"
#include "world.h"

namespace walls {

Plant::Plant(World* world, const MapLocation& location) :
    Object(world, location) {}

Plant::~Plant() {}

void Plant::die() {
    getWorld()->getPlants()->remove(this);
    getWorld()->getMap()->getBlock(getLocation())->removePlant(this);
    delete this;
}

} // walls
