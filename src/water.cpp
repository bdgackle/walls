/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "water.h"

namespace walls {

Water::Water() :
    m_depth(1024),
    m_pressure(0),
    m_contained(false),
    m_active(true) {}

Water::~Water() {}

virtual void init(const MapLocation& location, World* world)
{
    m_world = world;
    m_location = location;

    m_depth = 1024;
    m_pressure = m_depth;
}

} // walls
