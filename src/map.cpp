/**
 *  @author Barry Gackle
 */

// C Standard Headers
#include <stddef.h>

// C++ Standard Headers
#include <vector>

// Internal Headers
#include "map.h"
#include "maplocation.h"
#include "block.h"

namespace walls{

using std::vector;

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
m_block_count(m_height * m_width * m_depth) {}

Map::~Map()
{
    if (m_blocks != NULL)
        delete [] m_blocks;
}

void Map::init()
{
    m_blocks = new Block[m_block_count];
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

int Map::getHeight() const { return m_height; }

int Map::getWidth() const { return m_width; }

int Map::getDepth() const { return m_depth; }

int Map::getBlockCount() const { return m_block_count; }

int Map::getMaxIndex() const { return m_block_count - 1; }

const Block& Map::getBlock(const MapLocation& location) const
{
    int index = location.getIndex();
    return m_blocks[index];
}

Block* Map::getBlock(const MapLocation& location)
{
    int index = location.getIndex();
    return getBlock(index);
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

void Map::getEdges(vector<int>* edges, int depth) const
{
    int layer_base = depth * getWidth() * getHeight();
    int top_base = layer_base;
    int bottom_base = layer_base + getWidth() * (getHeight() - 1);

    vector<bool> done;
    done.resize(getBlockCount());
    // TODO: Slow... use std::map for this
    for (int i = 0; i < done.size(); i++) {
        done.at(i) = false;
    }

    for (int x = 0; x < getWidth(); x++) {
        pushIndex(top_base + x, edges, &done);
        pushIndex(bottom_base + x, edges, &done);
    }

    int left_base = layer_base;
    int right_base = layer_base + (getHeight() - 1);
    for (int y = 0; y < getHeight(); y++) {
        int offset = getWidth() * y;
        pushIndex(left_base + offset, edges, &done);
        pushIndex(right_base + offset, edges, &done);
    }
}

void Map::pushIndex(int index, vector<int>* list, vector<bool>* done) const
{
    if (done->at(index) == false) {
        list->push_back(index);
        done->at(index) = true;
    }
}

} // walls
