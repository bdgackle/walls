/**
 *  @author Barry Gackle
 *  @author 23 June 2014
 */
// C Standard Headers
#include <stddef.h>

// C++ Standard Headers
#include <vector>

// Internal Headers
#include "map.h"
#include "game_constants.h"
#include "maplocation.h"
#include "block.h"

namespace walls{

using std::vector;

Map::Map(int width, int height, int depth) :
m_width(width),
m_height(height),
m_depth(depth)
{
    m_blocks = new Block[m_height * m_width * m_depth];
}

Map::~Map()
{
    if (m_blocks != NULL)
        delete [] m_blocks;
}

int Map::getHeight() const { return m_height; }

int Map::getWidth() const { return m_width; }

int Map::getDepth() const { return m_depth; }

bool Map::exists(const MapLocation& location) const
{
    MapLocation upper_north_west(0,0,0);
    MapLocation lower_south_east(getWidth(), getHeight(), getDepth());

    return location.isInSpace(upper_north_west, lower_south_east);
}

void Map::getEdges(vector<MapLocation>* edges, int depth)
{
    const int top = 0;
    const int bottom = getHeight() - 1;
    const int left = 0;
    const int right = getWidth() - 1;

    for (int x = 0; x < getWidth(); x++) {
        addLocationToList(MapLocation(x, top, depth), edges);
        addLocationToList(MapLocation(x, bottom, depth), edges);
    }

    for (int y = 0; y < getHeight(); y++) {
        addLocationToList(MapLocation(left, y, depth), edges);
        addLocationToList(MapLocation(right, y, depth), edges);
    }
}

int Map::getType(const MapLocation& location) const
{
    if (exists(location))
        return getBlock(location)->getType();
    else
        return NOT_ON_MAP;
}

bool Map::getIsOutdoors(const MapLocation& location) const
{
    if (exists(location))
        return getBlock(location)->getIsOutdoors();
    else
        return false;
}

bool Map::getIsMovementBoundry(const MapLocation& location) const
{
    if (exists(location))
        return getBlock(location)->getIsMovementBoundry();
    else
        return false;
}

bool Map::getIsIndoorBoundry(const MapLocation& location) const
{
    if (exists(location))
        return getBlock(location)->getIsIndoorBoundry();
    else
        return false;
}

bool Map::getIsUpdated(const MapLocation& location) const
{
    if (exists(location))
        return getBlock(location)->getIsUpdated();
    else
        return false;
}

void Map::setType(const MapLocation& location, BlockType type)
{
    if (exists(location))
        getBlock(location)->setType(type);
}

void Map::setIsOutdoors(const MapLocation& location, bool outdoors)
{
    if (exists(location))
        getBlock(location)->setIsOutdoors(outdoors);
}

void Map::setIsUpdated(const MapLocation& location, bool updated)
{
    if (exists(location))
        getBlock(location)->setIsUpdated(updated);
}

void Map::addLocationToList(const MapLocation& location,
                            vector<MapLocation>* list)
{
    if (exists(location) && !getIsUpdated(location)) {
        list->push_back(location);
        setIsUpdated(location, true);
    }
}

void Map::clearIsUpdated()
{
    for(int x = 0; x < getWidth(); x++) {
        for(int y = 0; y < getHeight(); y++) {
            for(int z = 0; z < getDepth(); z++) {
                setIsUpdated(MapLocation(x, y, z), false);
            }
        }
    }
}

void Map::clearIsOutdoors()
{
    for(int x = 0; x < getWidth(); x++) {
        for(int y = 0; y < getHeight(); y++) {
            for(int z = 0; z < getDepth(); z++) {
                setIsOutdoors(MapLocation(x, y, z), false);
            }
        }
    }
}

Block* Map::getBlock(const MapLocation& location) const
{
    int index = location.getIndex(getWidth(), getHeight(), getDepth());
    return &(m_blocks[index]);
}

} // walls
