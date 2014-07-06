/**
 *  @author Barry Gackle
 *  @author 29 June 2014
 */

// Internal Headers
#include "player.h"
#include "game_constants.h"
#include "maplocation.h"
#include "map.h"

namespace walls{

Player::Player() :
m_location(0, 0, 0),
m_status(HAPPY)
{
}

Player::~Player()
{
}

MapLocation Player::getLocation() const
{
    return m_location;
}

PlayerStatus Player::getStatus() const
{
    return m_status;
}

void Player::setLocation(const MapLocation& location, const Map *map)
{
    m_location = location;

    if (map->getIsOutdoors(location))
        setStatus(VENGEFUL);
    else
        setStatus(HAPPY);
}

void Player::setStatus(PlayerStatus status)
{
    m_status = status;
}

} // walls
