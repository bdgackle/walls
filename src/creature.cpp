/**
 *  @author Barry Gackle
 *  @author 6 July 2014
 */

// Internal Headers
#include "creature.h"

namespace walls {

Creature::Creature() :
    m_world(NULL),
    m_location(0, 0, 0) {}

Creature::~Creature() {}

MapLocation Creature::getLocation() const
{
    return m_location;
}

void Creature::setLocation(const MapLocation& location)
{
    m_location = location;
}

} // walls
