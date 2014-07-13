/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "object.h"

namespace walls {

Object::Object(World* world, const MapLocation& location) :
    m_world(world),
    m_location(location),
    m_age(0) {}

Object::~Object() {}

MapLocation Object::getLocation() const { return m_location; } 
World* Object::getWorld() { return m_world; }

void Object::setLocation(const MapLocation& location) { m_location = location; }

void Object::update(int time)
{
    m_age += time;
}

} // walls
