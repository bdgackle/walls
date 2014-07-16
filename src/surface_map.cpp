/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "surface_map.h"
#include "maplocation.h"

namespace walls {

SurfaceMap::SurfaceMap(int width, int height) :
    m_width(width),
    m_height(height) {
    m_count = m_width * m_height;
    m_surface = new int[m_count];

    for (int i = 0; i < m_count; i++) {
        m_surface[i] = 0;
    }
}

SurfaceMap::~SurfaceMap() { delete [] m_surface; }

int SurfaceMap::getSurfaceDepth(const MapLocation& location) const {
    return getDepth(location.getX(), location.getY());
}

bool SurfaceMap::isOnSurface(const MapLocation& location) const {
    return getSurfaceDepth(location) == location.getZ();
}

bool SurfaceMap::isBelowSurface(const MapLocation& location) const {
    return getSurfaceDepth(location) < location.getZ();
}

bool SurfaceMap::isAboveSurface(const MapLocation& location) const {
    return getSurfaceDepth(location) > location.getZ();
}

int SurfaceMap::getDepth(int x, int y) const {
    int index = getIndex(x,y);

    if ((index < m_count) && (index > 0))
        return m_surface[index];
    else
        return -1;
}

int SurfaceMap::getIndex(int x, int y) const {
    return y * m_width + x;
}

} // walls
