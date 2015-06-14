/**
 *  @author Barry Gackle
 */

// Local Headers
#include "object.hpp"

namespace walls {

Object::Object(World* world, const MapLocation& location) :
    m_world(world),
    m_location(location),
    m_age(0),
    m_id(m_next_id++),
    m_is_dead(false) {}

MapLocation Object::getLocation() const
{
    return m_location;
}

bool Object::getIsDead() const
{
    return m_is_dead;
}

int Object::getAge() const
{
    return m_age;
}

void Object::setLocation(const MapLocation& location)
{
    m_location = location;
}

void Object::setIsDead()
{
    m_is_dead = true;
}

void Object::update(int time)
{
    m_age += time;
}

int Object::m_next_id = 0;

} // namespace walls
