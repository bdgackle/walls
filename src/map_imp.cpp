/**
 *  @author Barry Gackle
 */

// Local Headers
#include "map_imp.hpp"
#include "maplocation.hpp"
#include "block.hpp"
#include "update_map.hpp"

// C Standard Headers
#include <stddef.h>

// C++ Standard Headers
#include <vector>

using std::vector;

namespace walls {

MapImp::MapImp(int width, int height, int depth) :
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
            isEdge(MapLocation(x, m_n_bound, z), true);
            isEdge(MapLocation(x, m_s_bound, z), true);
        }
        for (int y = m_n_bound; y < m_height; y++) {
            isEdge(MapLocation(m_e_bound, y, z), true);
            isEdge(MapLocation(m_w_bound, y, z), true);
        }
    }
}

MapImp::~MapImp()
{
    delete [] m_blocks;
}

int MapImp::height() const
{
    return m_height;
}

int MapImp::width() const
{
    return m_width;
}

int MapImp::depth() const
{
    return m_depth;
}

int MapImp::blockCount() const
{
    return m_block_count;
}

bool MapImp::exists(int index) const
{
    if ((index < 0) || (index >= m_block_count))
        return false;
    else
        return true;
}

bool MapImp::exists(const MapLocation& location) const
{
    if ((location.getX() < m_w_bound) || (location.getX() > m_e_bound) ||
        (location.getY() < m_n_bound) || (location.getY() > m_s_bound) ||
        (location.getZ() < m_u_bound) || (location.getZ() > m_d_bound))
        return false;
    else
        return true;
}

void MapImp::edges(vector<int>* edges, int depth) const
{
    int layer_base = depth * width() * height();
    int top_base = layer_base;
    int bottom_base = layer_base + width() * (height() - 1);

    UpdateMap updated(blockCount());

    for (int x = 0; x < width(); x++) {
        pushIndex(top_base + x, edges, &updated);
        pushIndex(bottom_base + x, edges, &updated);
    }

    int left_base = layer_base;
    int right_base = layer_base + (height() - 1);
    for (int y = 0; y < height(); y++) {
        int offset = width() * y;
        pushIndex(left_base + offset, edges, &updated);
        pushIndex(right_base + offset, edges, &updated);
    }
}

void MapImp::adjacent(const MapLocation& location,
                      vector<MapLocation>* adjacent,
                      int distance) const
{
    int x = location.getX();
    int y = location.getX();
    int z = location.getZ();

    for (int i = 1; i < distance; i++) {
        adjacent->push_back(MapLocation(x + i, y - distance + i, 0));
        adjacent->push_back(MapLocation(x + i, y + distance - i, 0));
        adjacent->push_back(MapLocation(x - i, y - distance - i, 0));
        adjacent->push_back(MapLocation(x - i, y + distance - i, 0));
    }
}

BlockType MapImp::blockType(const MapLocation& loc) const
{
    return block(loc).getType();
}

bool MapImp::isOutdoors(const MapLocation& loc) const
{
    return block(loc).getIsOutdoors();
}

bool MapImp::isEdge(int index) const
{
    return block(index).getIsEdge();
}

bool MapImp::isEdge(const MapLocation& loc) const
{
    return block(loc).getIsEdge();
}

bool MapImp::isMovementBoundry(const MapLocation& loc) const
{
    return block(loc).getIsMovementBoundry();
}

bool MapImp::isIndoorBoundry(int index) const
{
    return block(index).getIsIndoorBoundry();
}

bool MapImp::isIndoorBoundry(const MapLocation& loc) const
{
    return block(loc).getIsIndoorBoundry();
}

bool MapImp::hasCreature(const MapLocation& loc) const
{
    return block(loc).getHasCreature();
}

bool MapImp::hasPlant(const MapLocation& loc) const
{
    return block(loc).getHasPlant();
}

bool MapImp::hasPrey(const MapLocation& loc) const
{
    return block(loc).getHasPrey();
}

void MapImp::blockType(const MapLocation& loc, BlockType type)
{
    block(loc)->setType(type);
}

void MapImp::isOutdoors(int index, bool outdoors)
{
    block(index)->setIsOutdoors(outdoors);
}

void MapImp::isOutdoors(const MapLocation& loc, bool outdoors)
{
    block(loc)->setIsOutdoors(outdoors);
}

void MapImp::isEdge(const MapLocation& loc, bool edge)
{
    block(loc)->setIsEdge(edge);
}

void MapImp::addCreature(const MapLocation& loc, Object* creature)
{
    block(loc)->addCreature(creature);
}

void MapImp::addPlant(const MapLocation& loc, Object* plant)
{
    block(loc)->addPlant(plant);
}

void MapImp::addPrey(const MapLocation& loc, Object* prey)
{
    block(loc)->addPrey(prey);
}

void MapImp::removeCreature(const MapLocation& loc, Object* creature)
{
    block(loc)->removeCreature(creature);
}

void MapImp::removePlant(const MapLocation& loc, Object* plant)
{
    block(loc)->removePlant(plant);
}

void MapImp::removePrey(const MapLocation& loc, Object* prey)
{
    block(loc)->removePrey(prey);
}

const Object& MapImp::creature(const MapLocation& loc) const
{
    return block(loc).getCreature();
}

Object* MapImp::creature(const MapLocation& loc)
{
    return block(loc)->getCreature();
}

const Object& MapImp::plant(const MapLocation& loc) const
{
    return block(loc).getPlant();
}

Object* MapImp::plant(const MapLocation& loc)
{
    return block(loc)->getPlant();
}

const Object& MapImp::prey(const MapLocation& loc) const
{
    return block(loc).getPrey();
}

Object* MapImp::prey(const MapLocation& loc)
{
    return block(loc)->getPrey();
}

const Block& MapImp::block(const MapLocation& loc) const
{
    if (exists(loc))
        return block(loc.getIndex());
    else
        return m_invalid_block;
}

Block* MapImp::block(const MapLocation& location)
{
    if (exists(location))
        return block(location.getIndex());
    else
        return &m_invalid_block;
}

const Block& MapImp::block(int index) const
{
    return m_blocks[index];
}

Block* MapImp::block(int index)
{
    return &(m_blocks[index]);
}

void MapImp::pushIndex(int index, vector<int>* list, UpdateMap* done) const
{
    if (done->get(index) == false) {
        list->push_back(index);
        done->set(index);
    }
}

void MapImp::clearIsOutdoors()
{
    for (int i = 0; i < m_block_count; i++) {
        m_blocks[i].setIsOutdoors(false);
    }
}

} // namespace walls
