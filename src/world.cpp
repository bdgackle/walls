/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// External Headers
#include <time.h>
#include <stdio.h>

// Internal Headers
#include "world.h"
#include "boundry_scanner.h"
#include "map.h"
#include "maplocation.h"
#include "player.h"

namespace walls{

World::World(int width, int height, int depth) :
m_map(width, height, depth),
m_scanner(&m_map),
m_boundries_dirty(true)
{
    sprintf(m_update_time, "% 7d", 0);
    m_player.setLocation(MapLocation(0, 3, 0), &m_map);
}

World::~World() {}

void World::update()
{
    clock_t start = clock();
    if (getBoundriesDirty())
    {
        m_scanner.updateBoundry();
        setBoundriesDirty(false);
    }
    clock_t stop = clock();
    sprintf(m_update_time, "% 7d", stop - start);
}

void World::doCommand(Command command, const MapLocation& location)
{
    switch(command)
    {
        case PLAYER_NORTH:
            movePlayer(0, -1, 0);
            break;

        case PLAYER_SOUTH:
            movePlayer(0, 1, 0);
            break;

        case PLAYER_WEST:
            movePlayer(-1, 0, 0);
            break;

        case PLAYER_EAST:
            movePlayer(1, 0, 0);
            break;

        case ADD_WALL:
            addWall(location);
            break;

        case ADD_GROUND:
            addGround(location);
            break;

        case ADD_DOOR:
            addDoor(location);
            break;
    }

    update();
}

MapLocation World::getPlayerLocation() const
{
    return m_player.getLocation();
}

PlayerStatus World::getPlayerStatus() const
{
    return m_player.getStatus();
}

BlockType World::getBlockType(const MapLocation& location) const
{
    return m_map.getType(location);
}

void World::movePlayer(int delta_x, int delta_y, int delta_z)
{
    MapLocation old_loc = m_player.getLocation();
    MapLocation new_loc = old_loc.getRelative(delta_x, delta_y, delta_z);

    // Movement only happens if new location exists and is passable
    if ((m_map.exists(new_loc)) &&
        !(m_map.getIsMovementBoundry(new_loc)))
    {
        m_player.setLocation(new_loc, &m_map);
    }
}

void World::addWall(const MapLocation& location)
{
    m_map.setType(location, WALL);
    setBoundriesDirty(true);
}

void World::addDoor(const MapLocation& location)
{
    m_map.setType(location, DOOR);
    setBoundriesDirty(true);
}

void World::addGround(const MapLocation& location)
{
    m_map.setType(location, GROUND);
    setBoundriesDirty(true);
}

void World::setBoundriesDirty(bool dirty)
{
    m_boundries_dirty = dirty;
}

bool World::getBoundriesDirty() const
{
    return m_boundries_dirty;
}

} // walls