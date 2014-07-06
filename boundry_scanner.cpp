/**
 *  @author Barry Gackle
 *  @author 23 June 2014
 */

// Internal Includes
#include "boundry_scanner.h"
#include "map.h"
#include "maplocation.h"

namespace walls{

BoundryScanner::BoundryScanner(Map *map) :
m_map(map),
m_perf_count(0)
{
}

BoundryScanner::~BoundryScanner()
{
}

void BoundryScanner::updateBoundry()
{
    clock_t start = clock();
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
    clock_t stop = clock();
    clock_t elapse = (stop - start);
}

void BoundryScanner::popLocation()
{
    MapLocation location = m_stack.back();
    m_stack.pop_back();

    if (!(m_map->getIsIndoorBoundry(location)))
    {
        pushLocation(location.getN());
        pushLocation(location.getS());
        pushLocation(location.getE());
        pushLocation(location.getW());

        m_map->setIsOutdoors(location, true);
    }
}

void BoundryScanner::pushLocation(MapLocation location)
{
    if ((m_map->exists(location)) && !(m_map->getIsUpdated(location)))
    {
        m_stack.push_back(location);
        m_map->setIsUpdated(location, true);
    }
}

} // walls
