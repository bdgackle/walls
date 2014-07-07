/**
 *  @author Barry Gackle
 *  @author 6 July 2014
 */

// Internal Headers
#include "creature.h"

namespace walls {

Creature::Creature() :
    m_map(NULL),
    m_location(0, 0, 0) {}

Creature::~Creature() {}

void Creature::setLocation(MapLocation location)
{
    m_location = location;
}

MapLocation Creature::getLocation() const
{
    return m_location;
}

} // walls
