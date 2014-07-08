/**
 *  @author Barry Gackle
 */

// C Standard Headers
#include <stddef.h>

// Internal Headers
#include "player.h"
#include "game_constants.h"
#include "world.h"
#include "maplocation.h"
#include "map.h"
#include "block.h"

namespace walls{

Player::Player() :
m_status(HAPPY),
m_world(NULL) {}

Player::~Player() {}

void Player::init(World* world)
{
    m_world = world;
}

PlayerStatus Player::getStatus() const { return m_status; }

MapLocation Player::getLocation() const { return m_location; }

void Player::move(int d_x, int d_y, int d_z)
{
    MapLocation dest = m_location.getRelative(d_x, d_y, d_z);

    if ((m_world->getMap()->exists(dest)) &&
        !(m_world->getMap()->getBlock(dest)->getIsMovementBoundry())) {

        setLocation(dest);
    }
}

void Player::setLocation(const MapLocation& location)
{
    m_location = location;

    if (m_world->getMap()->getBlock(location)->getIsOutdoors())
        setStatus(VENGEFUL);
    else
        setStatus(HAPPY);
}

void Player::setStatus(PlayerStatus status) { m_status = status; }

} // walls
