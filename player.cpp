/**
 *  @author Barry Gackle
 *  @author 29 June 2014
 */

// Internal Headers
#include "maplocation.h"
#include "map.h"
#include "player.h"

namespace walls{

Player::Player() :
m_location(0, 0, 0),
m_status(STATUS_HAPPY)
{
}

Player::~Player()
{
}

MapLocation Player::getLocation() const
{
    return m_location;
}

int Player::getStatus() const
{
    return m_status;
}

void Player::setLocation(const MapLocation& location, const Map *map)
{
    m_location = location;

    if (map->getIsOutdoors(location))
        setStatus(STATUS_VENGEFUL);
    else
        setStatus(STATUS_HAPPY);
}

void Player::setStatus(int status)
{
    m_status = status;
}

} // walls
