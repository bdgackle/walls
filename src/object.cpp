/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "object.h"

namespace walls {

Object::Object(World* world, const MapLocation& location) :
    m_world(world),
    m_location(location),
    m_age(0),
    m_id(m_next_id++),
    m_is_dead(false) {}

Object::~Object() {}

MapLocation Object::getLocation() const { return m_location; } 

bool Object::getIsDead() const { return m_is_dead; }

void Object::setLocation(const MapLocation& location) { m_location = location; }

void Object::setIsDead() { m_is_dead = true; }

void Object::update(int time) { m_age += time; }

int Object::m_next_id = 0;

} // walls
