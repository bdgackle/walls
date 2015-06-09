/**
 *  @author Barry Gackle
 */

// C Standard Headers
#include <stddef.h>

// C++ Standard Headers
#include <list>

// Internal Headers
#include "map.hpp"
#include "maplocation.hpp"
#include "block.hpp"
#include "update_map.hpp"

using std::list;

namespace walls {

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
    m_block_count(m_height * m_width * m_depth)
{
    m_blocks = new Block[m_block_count];
    m_invalid_block.setType(NOT_ON_MAP);
    MapLocation::setDimensions(m_width, m_height, m_depth);

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
    delete [] m_blocks;
}

int Map::getHeight() const
{
    return m_height;
}

int Map::getWidth() const
{
    return m_width;
}

int Map::getDepth() const
{
    return m_depth;
}

int Map::getBlockCount() const
{
    return m_block_count;
}

int Map::getMaxIndex() const
{
    return m_block_count - 1;
}

const Block& Map::getBlock(const MapLocation& location) const
{
    if (exists(location))
        return m_blocks[location.getIndex()];
    else
        return m_invalid_block;
}

Block* Map::getBlock(const MapLocation& location)
{
    if (exists(location))
        return getBlock(location.getIndex());
    else
        return &m_invalid_block;
}

const Block& Map::getBlock(int index) const
{
    return m_blocks[index];
}

Block* Map::getBlock(int index)
{
    return &(m_blocks[index]);
}

bool Map::exists(const MapLocation& location) const
{
    if ((location.getX() < m_w_bound) || (location.getX() > m_e_bound) ||
        (location.getY() < m_n_bound) || (location.getY() > m_s_bound) ||
        (location.getZ() < m_u_bound) || (location.getZ() > m_d_bound))
        return false;
    else
        return true;
}

bool Map::exists(int index) const
{
    if ((index < 0) || (index > getMaxIndex()))
        return false;
    else
        return true;
}

void Map::getEdges(list<int>* edges, int depth) const
{
    int layer_base = depth * getWidth() * getHeight();
    int top_base = layer_base;
    int bottom_base = layer_base + getWidth() * (getHeight() - 1);

    UpdateMap updated(getBlockCount());

    for (int x = 0; x < getWidth(); x++) {
        pushIndex(top_base + x, edges, &updated);
        pushIndex(bottom_base + x, edges, &updated);
    }

    int left_base = layer_base;
    int right_base = layer_base + (getHeight() - 1);
    for (int y = 0; y < getHeight(); y++) {
        int offset = getWidth() * y;
        pushIndex(left_base + offset, edges, &updated);
        pushIndex(right_base + offset, edges, &updated);
    }
}

void Map::getAdjacent(const MapLocation& location,
                      list<MapLocation>* adjacent,
                      int distance) const
{
    int x = location.getX();
    int y = location.getX();
    int z = location.getZ();
    /*
    MapLocation north(x, y - distance, z);
    MapLocation south(x, y + distance, z);
    MapLocation east(x + distance, y, z);
    MapLocation west(x - distance, y, z);

    MapLocation north = location.getRelative(0, -distance, 0);
    MapLocation south = location.getRelative(0, distance, 0);
    MapLocation east = location.getRelative(distance, 0, 0);
    MapLocation west = location.getRelative(-distance, 0, 0);
    */

    for (int i = 1; i < distance; i++) {
        adjacent->push_back(MapLocation(x + i, y - distance + i, 0));
        adjacent->push_back(MapLocation(x + i, y + distance - i, 0));
        adjacent->push_back(MapLocation(x - i, y - distance - i, 0));
        adjacent->push_back(MapLocation(x - i, y + distance - i, 0));
    /*
        adjacent->push_back(north.getRelative(i, i, 0));
        adjacent->push_back(south.getRelative(-i, -i, 0));
        adjacent->push_back(east.getRelative(-i, i, 0));
        adjacent->push_back(west.getRelative(i, -i, 0));
    */
    }
}

void Map::pushIndex(int index, list<int>* list, UpdateMap* done) const
{
    if (done->get(index) == false) {
        list->push_back(index);
        done->set(index);
    }
}

} // walls
