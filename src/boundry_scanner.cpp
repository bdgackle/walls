/**
 *  @author Barry Gackle
 *  @author 23 June 2014
 */

// Internal Includes
#include "boundry_scanner.hpp"
#include "map.hpp"
#include "maplocation.hpp"

namespace walls {

BoundryScanner::BoundryScanner(Map *map) :
    m_map(map),
    m_updated(map->blockCount()) {}

void BoundryScanner::updateBoundry()
{
    int block_count = m_map->blockCount();

    m_updated.reset();
    m_map->clearIsOutdoors();

    for (int z = 0; z < m_map->depth(); z++) {
        m_map->edges(&m_stack, z);
    }

    while (m_stack.size() > 0) {
        popLocation();
    }
}

void BoundryScanner::popLocation()
{
    int index = m_stack.back();
    m_stack.pop_back();

    if (!(m_map->isIndoorBoundry(index))) {
        int northern_neighbor = index - m_map->width();
        int southern_neighbor = index + m_map->width();
        int eastern_neighbor = index + 1;
        int western_neighbor = index - 1;

        if (!(m_map->isEdge(index))) {
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

        m_map->isOutdoors(index, true);
    }
}

void BoundryScanner::pushLocation(int index)
{
    if (m_updated.getFast(index) == false) {
        m_stack.push_back(index);
        m_updated.setFast(index);
    }
}

} // namespace walls
