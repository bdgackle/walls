/**
 *  @author Barry Gackle
 */

// Local Headers
#include "object_imp.hpp"

namespace walls {

ObjectImp::ObjectImp(World* world, const MapLocation& location) :
    m_world(world),
    m_location(location),
    m_is_dead(false) {}

MapLocation ObjectImp::getLocation() const
{
    return m_location;
}

bool ObjectImp::getIsDead() const
{
    return m_is_dead;
}

void ObjectImp::setLocation(const MapLocation& location)
{
    m_location = location;
}

void ObjectImp::setIsDead()
{
    m_is_dead = true;
}

} // namespace walls
