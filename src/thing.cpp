/**
 *  @author Barry Gackle
 *  @author 6 July 2014
 */

// C Standard Headers
#include <stddef.h>

// Internal Headers
#include "thing.h"
#include "game_constants.h"

namespace walls {

Thing::Thing() :
    m_world(NULL),
    m_location(0, 0, 0),
    m_valid(true) {}

Thing::~Thing() {}

MapLocation Thing::getLocation() const { return m_location; }

void Thing::setLocation(const MapLocation& location) { m_location = location; }

bool Thing::getValid() const { return m_valid; }

ThingType Thing::getType() const { return m_type; }

} // walls
