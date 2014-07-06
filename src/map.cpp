/**
 *  @author Barry Gackle
 *  @author 23 June 2014
 */

// C Standard Headers
#include <stddef.h>

// C++ Standard Headers
#include <deque>

// Internal Headers
#include "map.h"
#include "game_constants.h"
#include "maplocation.h"
#include "block.h"

namespace walls{

using std::deque;

Map::Map(int width, int height, int depth) :
m_width(width),
m_height(height),
m_depth(depth),
m_n_bound(0),
m_s_bound(height - 1),
m_e_bound(width - 1),
m_w_bound(0),
m_u_bound(0),
m_d_bound(depth - 1),
m_max_index(m_height * m_width * m_depth - 1)
{
    m_blocks = new Block[m_max_index + 1];
    MapLocation::setDimensions(m_width, m_height, m_depth);

    // Profiling showed that most of the CPU consumed in doing indoor/outdoor
    // calculation was in the 'exists' function.  By defining edges ahead of
    // time, and then handling edge tiles carefully, we can avoid ever adding
    // non-existant tiles to queue, so we won't need to check
    for (int z = m_u_bound; z < m_depth; z++) {

        for (int x = m_w_bound; x < m_width; x++) {
            getBlock(MapLocation(x, m_n_bound, z))->setIsEdge(true);
            getBlock(MapLocation(x, m_s_bound, z))->setIsEdge(true);
        }

        for (int y = m_n_bound; y < m_height; y++) {
            getBlock(MapLocation(m_e_bound, y, z))->setIsEdge(true);
            getBlock(MapLocation(m_w_bound, y, z))->setIsEdge(true);
        }
    }
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
    int x = location.getX();
    int y = location.getY();
    int z = location.getZ();

    if (x < m_w_bound)
        return false;
    else if (x > m_e_bound)
        return false;
    else if (y < m_n_bound)
        return false;
    else if (y > m_s_bound)
        return false;
    else if (z < m_u_bound)
        return false;
    else if (z > m_d_bound)
        return false;
    else
        return true;
}

bool Map::exists(int index) const
{
    if ((index < 0) || (index > m_max_index))
        return false;
    else
        return true;
}

void Map::getEdges(deque<int>* edges, int depth)
{
    int layer_base = depth * getWidth() * getHeight();
    int top_base = layer_base;
    int bottom_base = layer_base + getWidth() * (getHeight() - 1);

    for (int x = 0; x < getWidth(); x++) {
        addLocationToList(top_base + x, edges);
        addLocationToList(bottom_base + x, edges);
    }

    int left_base = layer_base;
    int right_base = layer_base + (getHeight() - 1);
    for (int y = 0; y < getHeight(); y++) {
        int offset = getWidth() * y;
        addLocationToList(left_base + offset, edges);
        addLocationToList(right_base + offset, edges);
    }
}

BlockType Map::getType(const MapLocation& location) const
{
    return getBlock(location)->getType();
}

BlockType Map::getType(int index) const
{
    return getBlock(index)->getType();
}

bool Map::getIsOutdoors(const MapLocation& location) const
{
    return getBlock(location)->getIsOutdoors();
}

bool Map::getIsOutdoors(int index) const
{
    return getBlock(index)->getIsOutdoors();
}

bool Map::getIsMovementBoundry(const MapLocation& location) const
{
    return getBlock(location)->getIsMovementBoundry();
}

bool Map::getIsMovementBoundry(int index) const
{
    return getBlock(index)->getIsMovementBoundry();
}

bool Map::getIsIndoorBoundry(const MapLocation& location) const
{
    return getBlock(location)->getIsIndoorBoundry();
}

bool Map::getIsIndoorBoundry(int index) const
{
    return getBlock(index)->getIsIndoorBoundry();
}

bool Map::getIsUpdated(const MapLocation& location) const
{
    return getBlock(location)->getIsUpdated();
}

bool Map::getIsUpdated(int index) const
{
    return getBlock(index)->getIsUpdated();
}

bool Map::getIsEdge(const MapLocation& location) const
{
    return getBlock(location)->getIsEdge();
}

bool Map::getIsEdge(int index) const
{
    return getBlock(index)->getIsEdge();
}

void Map::setType(const MapLocation& location, BlockType type)
{
    getBlock(location)->setType(type);
}

void Map::setType(int index, BlockType type)
{
    getBlock(index)->setType(type);
}

void Map::setIsOutdoors(const MapLocation& location, bool outdoors)
{
    getBlock(location)->setIsOutdoors(outdoors);
}

void Map::setIsOutdoors(int index, bool outdoors)
{
    getBlock(index)->setIsOutdoors(outdoors);
}

void Map::setIsUpdated(const MapLocation& location, bool updated)
{
    getBlock(location)->setIsUpdated(updated);
}

void Map::setIsUpdated(int index, bool updated)
{
    getBlock(index)->setIsUpdated(updated);
}

void Map::addLocationToList(int index, deque<int>* list)
{
    if (!getIsUpdated(index)) {
        list->push_back(index);
        setIsUpdated(index, true);
    }
}

void Map::clearIsUpdated()
{
    for (int i = 0; i < m_max_index; i++)
        setIsUpdated(i, false);
}

void Map::clearIsOutdoors()
{
    for (int i = 0; i < m_max_index; i++)
        setIsOutdoors(i, false);
}

Block* Map::getBlock(const MapLocation& location) const
{
    int index = location.getIndex();
    return &(m_blocks[index]);
}

Block* Map::getBlock(int index) const
{
    return &(m_blocks[index]);
}

} // walls
