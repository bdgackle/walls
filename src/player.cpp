/**
 *  @author Barry Gackle
 */

// Local Headers
#include "player.hpp"
#include "game_constants.hpp"
#include "world.hpp"
#include "maplocation.hpp"
#include "map.hpp"
#include "block.hpp"

namespace walls {

Player::Player(World* world) :
    m_status(HAPPY),
    m_world(world) {}

PlayerStatus Player::getStatus() const
{
    return m_status;
}

MapLocation Player::getLocation() const
{
    return m_location;
}

void Player::move(int d_x, int d_y, int d_z)
{
    MapLocation dest = m_location.getRelative(d_x, d_y, d_z);

    if ((m_world->getMap()->exists(dest)) &&
        !(m_world->getMap()->isMovementBoundry(dest))) {

        setLocation(dest);
    }
}

void Player::setLocation(const MapLocation& location)
{
    m_location = location;

    if (m_world->getMap()->isOutdoors(location) == true)
        setStatus(VENGEFUL);
    else
        setStatus(HAPPY);
}

void Player::setStatus(PlayerStatus status)
{
    m_status = status;
}

} // namespace walls
