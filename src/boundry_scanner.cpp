/**
 *  @author Barry Gackle
 *  @author 23 June 2014
 */

// C Standard Includes
#include <stddef.h>

// Internal Includes
#include "boundry_scanner.h"
#include "map.h"
#include "block.h"

namespace walls{

BoundryScanner::BoundryScanner(Map *map) :
m_map(map),
m_updated(NULL) {}

BoundryScanner::~BoundryScanner()
{
    if (m_updated != NULL)
        delete [] m_updated;
}

void BoundryScanner::init(int map_size)
{
    m_updated = new bool[map_size];
}

void BoundryScanner::updateBoundry()
{
    int block_count = m_map->getBlockCount();

    for (int i = 0; i < block_count; i++) {
        m_map->getBlock(i)->setIsOutdoors(false);
        m_updated[i] = false;
    }

    for (int z = 0; z < m_map->getDepth(); z++) {
        m_map->getEdges(&m_stack, z);
    }

    while (m_stack.size() > 0) {
        popLocation();
    }
}

void BoundryScanner::popLocation()
{
    int index = m_stack.back();
    m_stack.pop_back();

    if (!(m_map->getBlock(index)->getIsIndoorBoundry())) {
        int northern_neighbor = index - m_map->getWidth();
        int southern_neighbor = index + m_map->getWidth();
        int eastern_neighbor = index + 1;
        int western_neighbor = index - 1;

        if (!(m_map->getBlock(index)->getIsEdge())) {
            pushLocation(northern_neighbor);
            pushLocation(southern_neighbor);
            pushLocation(eastern_neighbor);
            pushLocation(western_neighbor);
        }
        else {
            // Edges will have some neighbors that don't exist.  By only
            // checking for existance here, we eliminate calls to the existance
            // check for all non-edge squares, hopefully saving some CPU
            if (m_map->exists(northern_neighbor))
                pushLocation(northern_neighbor);

            if (m_map->exists(southern_neighbor))
                pushLocation(southern_neighbor);

            if (m_map->exists(eastern_neighbor))
                pushLocation(eastern_neighbor);

            if (m_map->exists(western_neighbor))
                pushLocation(western_neighbor);
        }

        m_map->getBlock(index)->setIsOutdoors(true);
    }
}

void BoundryScanner::pushLocation(int index)
{
    if (m_updated[index] == false) {
        m_stack.push_back(index);
        m_updated[index] = true;
    }
}

} // walls
