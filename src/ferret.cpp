/**
 *  @author Barry Gackle
 *  @author 6 July 2014
 */

// C Standard Library
#include "stdlib.h"

// Internal Headers
#include "ferret.h"

namespace walls {

Ferret::Ferret() {}

Ferret::~Ferret() {}

void Ferret::init(MapLocation location, Map* map)
{
    m_location = location;
    m_map = map;
}

void Ferret::update()
{
    int dir = rand() % 4;

    if (dir == 0)
        move(-1, 0, 0);
    else if (dir == 1)
        move(1, 0, 0);
    else if (dir == 2)
        move(0, -1, 0);
    else if (dir == 3)
        move(0, 1, 0);
}

char Ferret::getDisplayChar() const
{
    return 'f';
}

void Ferret::move(int d_x, int d_y, int d_z)
{
    MapLocation old_loc = getLocation();
    MapLocation new_loc = old_loc.getRelative(d_x, d_y, d_z);

    // Movement only happens if new location exists and is passable
    if ((m_map->exists(new_loc)) &&
        !(m_map->getIsMovementBoundry(new_loc)))
    {
        setLocation(new_loc);
    }
}

} // walls
