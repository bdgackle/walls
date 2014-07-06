/**
 *  @author Barry Gackle
 *  @author 23 June 2014
 */

// Internal Includes
#include "boundry_scanner.h"
#include "map.h"

namespace walls{

BoundryScanner::BoundryScanner(Map *map) :
m_map(map)
{
}

BoundryScanner::~BoundryScanner()
{
}

void BoundryScanner::updateBoundry()
{
    m_map->clearIsUpdated();
    m_map->clearIsOutdoors();

    for (int z = 0; z < m_map->getDepth(); z++)
    {
        m_map->getEdges(&m_stack, z);
    }

    while (m_stack.size() > 0)
    {
        popLocation();
    }
}

void BoundryScanner::popLocation()
{
    int index = m_stack.back();
    m_stack.pop_back();

    if (!(m_map->getIsIndoorBoundry(index))) {
        int northern_neighbor = index - m_map->getWidth();
        int southern_neighbor = index + m_map->getWidth();
        int eastern_neighbor = index + 1;
        int western_neighbor = index - 1;

        if (!(m_map->getIsEdge(index))) {
            pushLocation(northern_neighbor);
            pushLocation(southern_neighbor);
            pushLocation(eastern_neighbor);
            pushLocation(western_neighbor);
        } else {
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

        m_map->setIsOutdoors(index, true);
    }
}

void BoundryScanner::pushLocation(int index)
{
    if (!(m_map->getIsUpdated(index)))
    {
        m_stack.push_back(index);
        m_map->setIsUpdated(index, true);
    }
}

} // walls
